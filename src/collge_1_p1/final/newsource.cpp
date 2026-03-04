/*
 * 水电煤气管理系统（高校场景）
 * 提示信息中文，ID用学号格式，输出换行
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;

// ------------------------- 公共事业类型 -------------------------

enum class Utility { Water, Electricity, Gas };

string toString(Utility u) {
    switch (u) {
        case Utility::Water: return "水";
        case Utility::Electricity: return "电";
        case Utility::Gas: return "气";
    }
    return "未知";
}

// ------------------------- 费率设置 -------------------------

struct Rate {
    double staffUnit;
    double studentSelfPayUnit;
};

class RateCard {
    unordered_map<Utility, Rate> rate_;
public:
    void set(Utility u, Rate r) { rate_[u] = r; }
    const Rate& get(Utility u) const { return rate_.at(u); }
};

// ------------------------- 用户类 -------------------------

class Human {
public:
    virtual ~Human() = default;
    virtual string id() const = 0;
    virtual string name() const = 0;
    virtual bool isStudent() const = 0;
    virtual double freeQuota(Utility u) const = 0;
};

class Student final : public Human {
    string id_, name_;
    unordered_map<Utility, double> quota_;
public:
    Student(string id, string name,
            unordered_map<Utility,double> quota)
        : id_(move(id)), name_(move(name)), quota_(move(quota)) {}

    string id() const override { return id_; }
    string name() const override { return name_; }
    bool isStudent() const override { return true; }
    double freeQuota(Utility u) const override {
        auto it = quota_.find(u);
        return it == quota_.end() ? 0.0 : it->second;
    }
};

class Staff final : public Human {
    string id_, name_;
public:
    Staff(string id, string name) : id_(move(id)), name_(move(name)) {}
    string id() const override { return id_; }
    string name() const override { return name_; }
    bool isStudent() const override { return false; }
    double freeQuota(Utility) const override { return 0.0; }
};

// ------------------------- 表计、抄表、账单 -------------------------

struct Meter {
    string meterId;
    Utility utility;
    string userId;
};

struct Reading {
    string meterId;
    Utility utility;
    double prevValue = 0.0;
    double currValue = 0.0;
    time_t tsPrev{};
    time_t tsCurr{};
    double usage() const { return max(0.0, currValue - prevValue); }
};

struct Bill {
    string billId, userId;
    Utility utility;
    double usage = 0.0, amount = 0.0;
    bool paid = false;
    time_t periodStart{}, periodEnd{};
};

// ------------------------- 策略 -------------------------

class PricingPolicy {
public:
    virtual ~PricingPolicy() = default;
    virtual double computeFee(const Human& user, Utility u, double usage,
                              const RateCard& card) const = 0;
};

class DefaultPricingPolicy : public PricingPolicy {
public:
    double computeFee(const Human& user, Utility u, double usage,
                      const RateCard& card) const override {
        const auto& r = card.get(u);
        if (user.isStudent()) {
            double free = user.freeQuota(u);
            return max(0.0, usage - free) * r.studentSelfPayUnit;
        } else {
            return usage * r.staffUnit;
        }
    }
};

// ------------------------- 仓库 -------------------------

class UserRepo {
    unordered_map<string, shared_ptr<Human>> users_;
public:
    void add(shared_ptr<Human> user) { users_[user->id()] = move(user); }
    shared_ptr<Human> get(const string& id) const { return users_.at(id); }
};

class MeterRepo {
    unordered_map<string, Meter> meters_;
public:
    void add(const Meter& m) { meters_[m.meterId] = m; }
    const Meter& get(const string& id) const { return meters_.at(id); }
};

// ------------------------- 服务 -------------------------

class BillingService {
    const UserRepo& users_;
    const MeterRepo& meters_;
    const RateCard& rates_;
    unique_ptr<PricingPolicy> policy_;
    vector<Bill> bills_;
public:
    BillingService(const UserRepo& u, const MeterRepo& m,
                   const RateCard& r, unique_ptr<PricingPolicy> p)
        : users_(u), meters_(m), rates_(r), policy_(move(p)) {}

    Bill generateBill(const Reading& rd) {
        const Meter& mt = meters_.get(rd.meterId);
        auto user = users_.get(mt.userId);
        double use = rd.usage();
        double fee = policy_->computeFee(*user, rd.utility, use, rates_);

        Bill b;
        b.billId = mt.meterId + "-" + to_string(rd.tsCurr);
        b.userId = mt.userId;
        b.utility = rd.utility;
        b.usage = use;
        b.amount = fee;
        b.paid = false;
        b.periodStart = rd.tsPrev;
        b.periodEnd = rd.tsCurr;
        bills_.push_back(b);
        return b;
    }

    const vector<Bill>& allBills() const { return bills_; }
};

int main() {
    UserRepo users;
    // 五个角色，ID用学号格式
    users.add(make_shared<Student>("2025218651","Nina",
        unordered_map<Utility,double>{{Utility::Water,5},{Utility::Electricity,30},{Utility::Gas,3}}));
    users.add(make_shared<Student>("2025218652","Kurisu",
        unordered_map<Utility,double>{{Utility::Water,6},{Utility::Electricity,25},{Utility::Gas,2}}));
    users.add(make_shared<Student>("2025218653","Alice",
        unordered_map<Utility,double>{{Utility::Water,4},{Utility::Electricity,28},{Utility::Gas,2.5}}));
    users.add(make_shared<Staff>("2025218654","Bob"));
    users.add(make_shared<Staff>("2025218655","Charlie"));

    MeterRepo meters;
    meters.add(Meter{"M-W-2025218651", Utility::Water, "2025218651"});
    meters.add(Meter{"M-E-2025218652", Utility::Electricity, "2025218652"});
    meters.add(Meter{"M-G-2025218653", Utility::Gas, "2025218653"});
    meters.add(Meter{"M-W-2025218654", Utility::Water, "2025218654"});
    meters.add(Meter{"M-E-2025218655", Utility::Electricity, "2025218655"});

    RateCard card;
    card.set(Utility::Water, Rate{1.5, 2.2});
    card.set(Utility::Electricity, Rate{0.8, 1.2});
    card.set(Utility::Gas, Rate{1.0, 1.5});

    BillingService svc(users, meters, card, make_unique<DefaultPricingPolicy>());

    time_t now = time(nullptr);
    // 模拟抄表数据
    svc.generateBill(Reading{"M-W-2025218651", Utility::Water, 10, 18, now-3600, now});
    svc.generateBill(Reading{"M-E-2025218652", Utility::Electricity, 100, 130, now-7200, now});
    svc.generateBill(Reading{"M-G-2025218653", Utility::Gas, 50, 54, now-3600, now});
    svc.generateBill(Reading{"M-W-2025218654", Utility::Water, 30, 32.5, now-3600, now});
    svc.generateBill(Reading{"M-E-2025218655", Utility::Electricity, 200, 240, now-3600, now});

    auto printBill = [](const Bill& b) {
        cout << "账单ID: " << b.billId << "\n"
             << "用户ID: " << b.userId << "\n"
             << "类型: " << toString(b.utility) << "\n"
             << "用量: " << b.usage << "\n"
             << "金额: " << b.amount << "\n"
             << "已缴: " << (b.paid?"是":"否") << "\n"
             << "-----------------------------\n";
    };

    // 中文提示交互
    cout << "请输入要查询的用户学号 (例如 2025218651 ~ 2025218655): ";
    string queryId;
    cin >> queryId;

    cout << "\n=== 用户 " << queryId << " 的账单 ===\n";
    for (auto& b : svc.allBills()) {
        if (b.userId == queryId) printBill(b);
    }

    return 0;
}

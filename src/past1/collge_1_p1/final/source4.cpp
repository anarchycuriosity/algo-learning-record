#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Human
{
protected:
    string name, id;
    // 三表各自的 id
    string waterId, electricId, gasId;

    double amountOfWaterLT, amountOfElectricLT, amountOfGasLT;
    double amountOfWaterNT, amountOfElectricNT, amountOfGasNT;

    // 新增成员：历史读数和缴费状态
    map<int, map<string, double>> history; // key: 时间(例如 202502 表示年月或 20250203 表示具体日期)
    string paymentStatus = "未缴";         // "已缴" 或 "未缴"

public:
    Human(string nname, string iid,
          const string& wId, const string& eId, const string& gId,
          double aamomntOfWaterLT, double aamountOfElectricLT, double aamountOfGasLT,
          double aamomntOfWaterNT, double aamountOfElectricNT, double aamountOfGasNT)
        : name(nname), id(iid),
          waterId(wId), electricId(eId), gasId(gId),
          amountOfWaterLT(aamomntOfWaterLT), amountOfWaterNT(aamomntOfWaterNT),
          amountOfElectricLT(aamountOfElectricLT), amountOfElectricNT(aamountOfElectricNT),
          amountOfGasLT(aamountOfGasLT), amountOfGasNT(aamountOfGasNT) {}

    virtual void showAll() = 0;

    // 新增接口：添加历史读数
    void addHistory(int timeKey, const map<string, double>& readings) {
        history[timeKey] = readings;
    }

    // 新增接口：获取某个时间点的读数（若不存在返回空 map）
    map<string, double> getHistory(int timeKey) const {
        auto it = history.find(timeKey);
        if (it != history.end()) return it->second;
        return {};
    }

    // 新增接口：遍历并打印历史（供派生类调用）
    void printHistory() const {
        if (history.empty()) {
            cout << "历史读数: 无" << endl;
            return;
        }
        cout << "历史读数:" << endl;
        for (const auto& kv : history) {
            cout << "  时间: " << kv.first << "  ";
            const auto& m = kv.second;
            // 为历史读数追加单位
            double w = (m.count("water") ? m.at("water") : 0);
            double e = (m.count("electric") ? m.at("electric") : 0);
            double g = (m.count("gas") ? m.at("gas") : 0);
            cout << "water=" << w << " L"
                 << " electric=" << e << " KWH"
                 << " gas=" << g << " L" << endl;
        }
    }

    // 新增接口：设置/获取缴费状态
    void setPaymentStatus(const string& status) { paymentStatus = status; }
    string getPaymentStatus() const { return paymentStatus; }

    // 设置 LT/NT 值（供 main 使用）
    void setLTValues(double w, double e, double g) {
        amountOfWaterLT = w; amountOfElectricLT = e; amountOfGasLT = g;
    }
    void setNTValues(double w, double e, double g) {
        amountOfWaterNT = w; amountOfElectricNT = e; amountOfGasNT = g;
    }

    // 打印三表 id（供调试/显示）
    void printMeterIds() const {
        cout << "meter ids: water=" << waterId << " electric=" << electricId << " gas=" << gasId << endl;
    }
    string getName() const { return name; }
};

class Staff : public Human
{
private:
    double perFeeOfWater, perFeeOfElectric, perFeeOfGas;
public:
    Staff(string nname, string iid,
          const string& wId, const string& eId, const string& gId,
          double aamountOfWaterLT, double aamountOfElectricLT, double aamountOfGasLT,
          double aamountOfWaterNT, double aamountOfElectricNT, double aamountOfGasNT,
          double pperFeeOfWater, double pperFeeOfElectric, double pperFeeOFGas)
        : Human(nname, iid, wId, eId, gId,
                aamountOfWaterLT, aamountOfElectricLT, aamountOfGasLT,
                aamountOfWaterNT, aamountOfElectricNT, aamountOfGasNT),
          perFeeOfWater(pperFeeOfWater), perFeeOfElectric(pperFeeOfElectric), perFeeOfGas(pperFeeOFGas) {}

    void showAll() override
    {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        printMeterIds();

        cout << "amount of water LT: " << amountOfWaterLT << " L" << endl;
        cout << "amount of electric LT: " << amountOfElectricLT << " KWH" << endl;
        cout << "amount of gas LT: " << amountOfGasLT << " L" << endl;

        cout << "amount of water NT: " << amountOfWaterNT << " L" << endl;
        cout << "amount of electric NT: " << amountOfElectricNT << " KWH" << endl;
        cout << "amount of gas NT: " << amountOfGasNT << " L" << endl;

        cout << "cost of water: " << (amountOfWaterNT - amountOfWaterLT) * perFeeOfWater << " 元" << endl;
        cout << "cost of electric: " << (amountOfElectricNT - amountOfElectricLT) * perFeeOfElectric << " 元" << endl;
        cout << "cost of gas: " << (amountOfGasNT - amountOfGasLT) * perFeeOfGas << " 元" << endl;

        // 打印历史和缴费状态
        printHistory();
        cout << "缴费状态: " << getPaymentStatus() << endl;
    }
};

class Student : public Human
{
private:
    double freeLimitOfWater, freeLimitOfElectric;
    double perFeeOfWater, perFeeOfElectric, perFeeOfGas;
public:
    Student(string nname, string iid,
            const string& wId, const string& eId, const string& gId,
            double aamountOfWaterLT, double aamountOfElectricLT, double aamountOfGasLT,
            double aamountOfWaterNT, double aamountOfElectricNT, double aamountOfGasNT,
            double pperFeeOfWater, double pperFeeOfElectric, double pperFeeOFGas,
            double ffreeLimitOfWater, double ffreeLimitOfElectric)
        : Human(nname, iid, wId, eId, gId,
                aamountOfWaterLT, aamountOfElectricLT, aamountOfGasLT,
                aamountOfWaterNT, aamountOfElectricNT, aamountOfGasNT),
          perFeeOfWater(pperFeeOfWater), perFeeOfElectric(pperFeeOfElectric), perFeeOfGas(pperFeeOFGas),
          freeLimitOfWater(ffreeLimitOfWater), freeLimitOfElectric(ffreeLimitOfElectric) {}

    void showAll() override
    {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        printMeterIds();

        cout << "amount of water LT: " << amountOfWaterLT << " L" << endl;
        cout << "amount of electric LT: " << amountOfElectricLT << " KWH" << endl;
        cout << "amount of gas LT: " << amountOfGasLT << " L" << endl;

        cout << "amount of water NT: " << amountOfWaterNT << " L" << endl;
        cout << "amount of electric NT: " << amountOfElectricNT << " KWH" << endl;
        cout << "amount of gas NT: " << amountOfGasNT << " L" << endl;

        if (amountOfWaterNT - amountOfWaterLT < freeLimitOfWater)
            cout << "cost of water: " << 0 << " 元" << endl;
        else
            cout << "cost of water: " << (amountOfWaterNT - amountOfWaterLT - freeLimitOfWater) * perFeeOfWater << " 元" << endl;

        if (amountOfElectricNT - amountOfElectricLT < freeLimitOfElectric)
            cout << "cost of electric: " << 0 << " 元" << endl;
        else
            cout << "cost of electric: " << (amountOfElectricNT - amountOfElectricLT - freeLimitOfElectric) * perFeeOfElectric << " 元" << endl;

        cout << "cost of gas: " << (amountOfGasNT - amountOfGasLT) * perFeeOfGas << " 元" << endl;

        // 打印历史和缴费状态
        printHistory();
        cout << "缴费状态: " << getPaymentStatus() << endl;
    }
};

 // diffFullMonths 保留原实现
int diffFullMonths(int startDate, int endDate) {
    int startYear  = startDate / 10000;
    int startMonth = (startDate / 100) % 100;
    int startDay   = startDate % 100;

    int endYear  = endDate / 10000;
    int endMonth = (endDate / 100) % 100;
    int endDay   = endDate % 100;

    int months = (endYear - startYear) * 12 + (endMonth - startMonth);
    months -= 1;
    if (months < 0) months = 0;
    return months;
}

int main()
{
    cout << "上一次录入数据的时间是20250203\n";
    //最初录入所有数据
    int ntMonth, quantity;
    cout << "输入现在所在时间和录入人数开始初始化\n";
    // 示例输入格式：202506 2
    cin >> ntMonth >> quantity;

    vector<Human*> people;


    cout << "依次输入人的类型(staff/student), 名字, 三个表的id(水 电 煤) 现在从"
         << ntMonth - 6
         << "月开始输入6个月以来的查表时间(水 电 煤表数据 每月末尾)\n"
            "然后输入 上一次缴费时间 上一次缴费的水电煤气量 缴费状态\n"
            "以下为输入示例(一行表示一个人):\n"
            "staff kurisu WID123 EID123 GID123 20250201 2 2 2 20250301 3 3 3 20250401 4 4 4 20250501 5 5 5 20250601 6 6 6 20250701 7 7 7 20250201 2 2 2 未缴\n";

    // 读取每个人的数据
    for (int i = 0; i < quantity; ++i) {
        string type, name;
        string wId, eId, gId;
        cin >> type >> name >> wId >> eId >> gId;

        // 读取 6 个月的抄表记录（每月一组：date water electric gas）
        int date;
        double w, e, g;
        int latestDate = 0;
        double latestW = 0, latestE = 0, latestG = 0;

        // 临时存储历史以便后面传入对象
        map<int, map<string,double>> tempHistory;

        for (int m = 0; m < 6; ++m) {
            if (!(cin >> date >> w >> e >> g)) {
                // 输入异常，清理并退出
                cerr << "输入格式错误或提前结束\n";
                return 1;
            }
            tempHistory[date] = { {"water", w}, {"electric", e}, {"gas", g} };
            if (date > latestDate) {
                latestDate = date;
                latestW = w; latestE = e; latestG = g;
            }
        }

        // 读取上一次缴费时间、上一次缴费的三表量、缴费状态
        int lastPayDate;
        double lastW, lastE, lastG;
        string payStatus;
        cin >> lastPayDate >> lastW >> lastE >> lastG >> payStatus;

        // 创建对象（这里用默认单价与免额示例值；你可以按需修改或扩展输入）
        // 为尽量少改动，Staff/Student 构造参数保持原样：LT/NT 先用占位，随后用 setLTValues/setNTValues 覆盖
        if (type == "staff") {
            Staff* s = new Staff(name, "id_" + name, wId, eId, gId,
                                 0,0,0, 0,0,0, 1.0, 0.5, 0.8);
            // 把历史写入
            for (const auto& kv : tempHistory) s->addHistory(kv.first, kv.second);
            // 设置 LT 为上次缴费量，NT 为最近一次抄表量
            s->setLTValues(lastW, lastE, lastG);
            s->setNTValues(latestW, latestE, latestG);
            s->setPaymentStatus(payStatus);
            people.push_back(s);
        } else { // student
            Student* st = new Student(name, "id_" + name, wId, eId, gId,
                                      0,0,0, 0,0,0, 1.0, 0.5, 0.8, 10.0, 20.0);
            for (const auto& kv : tempHistory) st->addHistory(kv.first, kv.second);
            st->setLTValues(lastW, lastE, lastG);
            st->setNTValues(latestW, latestE, latestG);
            st->setPaymentStatus(payStatus);
            people.push_back(st);
        }
    }

    // 提示用户输入名字来查找对应数据
    string queryName;
    cout << "请输入要查询的名字: ";
    cin >> queryName;

    bool found = false;
    for (Human* p : people) {
        if (p->getName() == queryName) {
            cout << "\n";
            p->showAll();
            found = true;
            break; // 找到就退出循环
        }
    }

    if (!found) {
        cout << "未找到该名字对应的数据。" << endl;
    }

    return 0;
}

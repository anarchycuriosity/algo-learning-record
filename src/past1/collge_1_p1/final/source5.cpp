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
    string waterId, electricId, gasId;

    double amountOfWaterLT, amountOfElectricLT, amountOfGasLT;
    double amountOfWaterNT, amountOfElectricNT, amountOfGasNT;

    map<int, map<string, double>> history;
    string paymentStatus = "未缴";

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

    void addHistory(int timeKey, const map<string, double>& readings) {
        history[timeKey] = readings;
    }

    map<string, double> getHistory(int timeKey) const {
        auto it = history.find(timeKey);
        if (it != history.end()) return it->second;
        return {};
    }

    void printHistory() const {
        if (history.empty()) {
            cout << "历史读数: 无" << endl;
            return;
        }
        cout << "历史读数:" << endl;
        for (const auto& kv : history) {
            cout << "  时间: " << kv.first << "  ";
            const auto& m = kv.second;
            double w = (m.count("water") ? m.at("water") : 0);
            double e = (m.count("electric") ? m.at("electric") : 0);
            double g = (m.count("gas") ? m.at("gas") : 0);
            cout << "water=" << w << " L"
                 << " electric=" << e << " KWH"
                 << " gas=" << g << " L" << endl;
        }
    }

    void setPaymentStatus(const string& status) { paymentStatus = status; }
    string getPaymentStatus() const { return paymentStatus; }

    void setLTValues(double w, double e, double g) {
        amountOfWaterLT = w; amountOfElectricLT = e; amountOfGasLT = g;
    }
    void setNTValues(double w, double e, double g) {
        amountOfWaterNT = w; amountOfElectricNT = e; amountOfGasNT = g;
    }

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

        double costOfWater = 0,costOfElectric = 0,costOfGas = 0;

            costOfWater = (amountOfWaterNT - amountOfWaterLT ) * perFeeOfWater;
            cout << "cost of water: " << costOfWater << " 元" << endl;
            costOfElectric = (amountOfElectricNT - amountOfElectricLT) * perFeeOfElectric;
            cout << "cost of Electric: " << costOfElectric << " 元" << endl;
            costOfGas = (amountOfGasNT - amountOfGasLT) * perFeeOfGas;
            cout << "cost of gas: " << costOfGas << " 元" << endl;
            cout << "cost of all: " << costOfWater + costOfElectric + costOfGas << " 元" << endl;

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

        double costOfWater = 0,costOfElectric = 0,costOfGas = 0;

        if (amountOfWaterNT - amountOfWaterLT < freeLimitOfWater)
            cout << "cost of water: " << costOfWater << " 元" << endl;
        else
        {
            costOfWater = (amountOfWaterNT - amountOfWaterLT - freeLimitOfWater) * perFeeOfWater;
            cout << "cost of water: " << costOfWater << " 元" << endl;
        }
        if (amountOfElectricNT - amountOfElectricLT < freeLimitOfElectric)
            cout << "cost of Electric: " << costOfElectric << " 元" << endl;
        else
        {
            costOfElectric = (amountOfElectricNT - amountOfElectricLT - freeLimitOfElectric) * perFeeOfElectric;
            cout << "cost of Electric: " << costOfElectric << " 元" << endl;
        }
        costOfGas = (amountOfGasNT - amountOfGasLT) * perFeeOfGas;
        cout << "cost of gas: " << costOfGas << " 元" << endl;
        cout << "cost of all: " << costOfWater + costOfElectric + costOfGas << " 元" << endl;

        printHistory();
        cout << "缴费状态: " << getPaymentStatus() << endl;
    }
};

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
    int ntMonth, quantity;
    cout << "输入现在所在时间和录入人数开始初始化\n";
    cin >> ntMonth >> quantity;

    vector<Human*> people;

    cout << "依次输入人的类型(staff/student), 名字, 三个表的id(水 电 煤) 从"
         << ntMonth - 6
         << "月开始输入6个月以来的查表时间(水 电 煤表数据 每月末尾)\n"
            "然后输入 上一次缴费时间 上一次缴费的水电煤气量 缴费状态\n"
            "以下为输入示例(一行表示一个人):\n"
            "staff kurisu WID123 EID123 GID123 20250201 2 2 2 20250301 3 3 3 20250401 4 4 4 20250501 5 5 5 20250601 6 6 6 20250701 7 7 7 20250201 2 2 2 未缴\n";

    for (int i = 0; i < quantity; ++i) {
        string type, name;
        string wId, eId, gId;
        cin >> type >> name >> wId >> eId >> gId;

        int date;
        double w, e, g;
        int latestDate = 0;
        double latestW = 0, latestE = 0, latestG = 0;

        map<int, map<string,double>> tempHistory;

        for (int m = 0; m < 6; ++m) {
            if (!(cin >> date >> w >> e >> g)) {
                cerr << "输入格式错误或提前结束\n";
                return 1;
            }
            tempHistory[date] = { {"water", w}, {"electric", e}, {"gas", g} };
            if (date > latestDate) {
                latestDate = date;
                latestW = w; latestE = e; latestG = g;
            }
        }

        int lastPayDate;
        double lastW, lastE, lastG;
        string payStatus;
        cin >> lastPayDate >> lastW >> lastE >> lastG >> payStatus;

        if (type == "staff") {
            Staff* s = new Staff(name, "id_" + name, wId, eId, gId,
                                 0,0,0, 0,0,0, 1.2, 0.7, 0.8);
            for (const auto& kv : tempHistory) s->addHistory(kv.first, kv.second);
            s->setLTValues(lastW, lastE, lastG);
            s->setNTValues(latestW, latestE, latestG);
            s->setPaymentStatus(payStatus);
            people.push_back(s);
        } else {
            Student* st = new Student(name, "id_" + name, wId, eId, gId,
                                      0,0,0, 0,0,0, 1.0, 0.5, 0.8, 10.0, 20.0);
            for (const auto& kv : tempHistory) st->addHistory(kv.first, kv.second);
            st->setLTValues(lastW, lastE, lastG);
            st->setNTValues(latestW, latestE, latestG);
            st->setPaymentStatus(payStatus);
            people.push_back(st);
        }
    }

    string queryName;
    cout << "请输入要查询的名字: ";
    cin >> queryName;

    bool found = false;
    for (Human* p : people) {
        if (p->getName() == queryName) {
            cout << "\n";
            p->showAll();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "未找到该名字对应的数据。" << endl;
    }

    return 0;
}

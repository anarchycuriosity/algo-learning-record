#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
#include <memory>
#include <iomanip>
using namespace std;

// 收费标准类（按照题目要求）
class FeeStandard {
public:
    double waterRate;        // 水费单价
    double electricRate;     // 电费单价
    double gasRate;         // 煤气费单价
    bool isStudent;         // 是否为学生标准
    
    FeeStandard(double w, double e, double g, bool stu = false)
        : waterRate(w), electricRate(e), gasRate(g), isStudent(stu) {}
};

// 表读数类
class MeterReading {
public:
    string meterId;
    int time;              // 格式：YYYYMM
    double lastReading;
    double currentReading;
    double usage;
    
    MeterReading(string id, int t, double last, double current)
        : meterId(id), time(t), lastReading(last), 
          currentReading(current), usage(current - last) {}
};

class Human {
protected:
    string name, id;
    vector<MeterReading> waterReadings;
    vector<MeterReading> electricReadings;
    vector<MeterReading> gasReadings;
    
    string paymentStatus = "未缴";
    double totalFee = 0.0;
    
public:
    Human(string nname, string iid) : name(nname), id(iid) {}
    
    virtual void showAll() = 0;
    virtual double calculateFee() = 0;
    
    void addWaterReading(const MeterReading& reading) {
        waterReadings.push_back(reading);
    }
    
    void addElectricReading(const MeterReading& reading) {
        electricReadings.push_back(reading);
    }
    
    void addGasReading(const MeterReading& reading) {
        gasReadings.push_back(reading);
    }
    
    void setPaymentStatus(const string& status) { 
        paymentStatus = status; 
    }
    
    string getPaymentStatus() const { return paymentStatus; }
    string getName() const { return name; }
    string getId() const { return id; }
    double getTotalFee() const { return totalFee; }
    
    void printRecentReadings() const {
        if (!waterReadings.empty()) {
            auto& w = waterReadings.back();
            cout << "水表: " << w.meterId 
                 << " 上次: " << w.lastReading << "L"
                 << " 本次: " << w.currentReading << "L"
                 << " 用量: " << w.usage << "L" << endl;
        }
        
        if (!electricReadings.empty()) {
            auto& e = electricReadings.back();
            cout << "电表: " << e.meterId 
                 << " 上次: " << e.lastReading << "KWH"
                 << " 本次: " << e.currentReading << "KWH"
                 << " 用量: " << e.usage << "KWH" << endl;
        }
        
        if (!gasReadings.empty()) {
            auto& g = gasReadings.back();
            cout << "煤气表: " << g.meterId 
                 << " 上次: " << g.lastReading << "m³"
                 << " 本次: " << g.currentReading << "m³"
                 << " 用量: " << g.usage << "m³" << endl;
        }
    }
    
    void printHalfYearHistory() const {
        cout << "=== 近6个月历史记录 ===" << endl;
        
        cout << "水费记录:" << endl;
        for (const auto& w : waterReadings) {
            cout << "  时间: " << w.time 
                 << " 读数: " << w.currentReading << "L" << endl;
        }
        
        cout << "电费记录:" << endl;
        for (const auto& e : electricReadings) {
            cout << "  时间: " << e.time 
                 << " 读数: " << e.currentReading << "KWH" << endl;
        }
        
        if (!gasReadings.empty()) {
            cout << "煤气记录:" << endl;
            for (const auto& g : gasReadings) {
                cout << "  时间: " << g.time 
                     << " 读数: " << g.currentReading << "m³" << endl;
            }
        }
    }
};

class Staff : public Human {
private:
    FeeStandard feeStandard;
    
public:
    Staff(string nname, string iid, double wRate = 1.2, double eRate = 0.7, double gRate = 0.8)
        : Human(nname, iid), feeStandard(wRate, eRate, gRate, false) {}
    
    double calculateFee() override {
        double waterFee = 0, electricFee = 0, gasFee = 0;
        
        if (!waterReadings.empty()) {
            auto& w = waterReadings.back();
            waterFee = w.usage * feeStandard.waterRate;
        }
        
        if (!electricReadings.empty()) {
            auto& e = electricReadings.back();
            electricFee = e.usage * feeStandard.electricRate;
        }
        
        if (!gasReadings.empty()) {
            auto& g = gasReadings.back();
            gasFee = g.usage * feeStandard.gasRate;
        }
        
        totalFee = waterFee + electricFee + gasFee;
        return totalFee;
    }
    
    void showAll() override {
        cout << "\n=== 教工信息 ===" << endl;
        cout << "姓名: " << name << endl;
        cout << "工号: " << id << endl;
        cout << "收费标准: 水" << feeStandard.waterRate 
             << "元/L, 电" << feeStandard.electricRate 
             << "元/KWH, 煤气" << feeStandard.gasRate << "元/m³" << endl;
        
        printRecentReadings();
        
        calculateFee();
        cout << "\n应缴费用:" << endl;
        cout << "水费: " << (waterReadings.empty() ? 0 : waterReadings.back().usage * feeStandard.waterRate) << "元" << endl;
        cout << "电费: " << (electricReadings.empty() ? 0 : electricReadings.back().usage * feeStandard.electricRate) << "元" << endl;
        cout << "煤气费: " << (gasReadings.empty() ? 0 : gasReadings.back().usage * feeStandard.gasRate) << "元" << endl;
        cout << "总计: " << totalFee << "元" << endl;
        
        printHalfYearHistory();
        cout << "缴费状态: " << paymentStatus << endl;
    }
};

class Student : public Human {
private:
    FeeStandard feeStandard;
    double freeWater;      // 免费水额度
    double freeElectric;   // 免费电额度
    
public:
    Student(string nname, string iid, 
            double wRate = 1.5, double eRate = 1.0,
            double fWater = 10.0, double fElectric = 20.0)
        : Human(nname, iid), feeStandard(wRate, eRate, 0, true),
          freeWater(fWater), freeElectric(fElectric) {}
    
    double calculateFee() override {
        double waterFee = 0, electricFee = 0;
        
        if (!waterReadings.empty()) {
            auto& w = waterReadings.back();
            double usage = w.usage;
            if (usage > freeWater) {
                waterFee = (usage - freeWater) * feeStandard.waterRate;
            }
        }
        
        if (!electricReadings.empty()) {
            auto& e = electricReadings.back();
            double usage = e.usage;
            if (usage > freeElectric) {
                electricFee = (usage - freeElectric) * feeStandard.electricRate;
            }
        }
        
        totalFee = waterFee + electricFee;
        return totalFee;
    }
    
    void showAll() override {
        cout << "\n=== 学生信息 ===" << endl;
        cout << "姓名: " << name << endl;
        cout << "学号: " << id << endl;
        cout << "免费额度: 水" << freeWater << "L, 电" << freeElectric << "KWH" << endl;
        cout << "超标收费标准: 水" << feeStandard.waterRate 
             << "元/L, 电" << feeStandard.electricRate << "元/KWH" << endl;
        
        printRecentReadings();
        
        calculateFee();
        cout << "\n应缴费用:" << endl;
        
        if (!waterReadings.empty()) {
            auto& w = waterReadings.back();
            double usage = w.usage;
            if (usage <= freeWater) {
                cout << "水费: 0元 (未超过免费额度)" << endl;
            } else {
                cout << "水费: " << (usage - freeWater) * feeStandard.waterRate 
                     << "元 (使用" << usage << "L, 超标" << (usage - freeWater) << "L)" << endl;
            }
        }
        
        if (!electricReadings.empty()) {
            auto& e = electricReadings.back();
            double usage = e.usage;
            if (usage <= freeElectric) {
                cout << "电费: 0元 (未超过免费额度)" << endl;
            } else {
                cout << "电费: " << (usage - freeElectric) * feeStandard.electricRate 
                     << "元 (使用" << usage << "KWH, 超标" << (usage - freeElectric) << "KWH)" << endl;
            }
        }
        
        cout << "总计: " << totalFee << "元" << endl;
        
        printHalfYearHistory();
        cout << "缴费状态: " << paymentStatus << endl;
    }
};

class WaterGasSystem {
private:
    vector<shared_ptr<Human>> users;
    
public:
    void addUser(shared_ptr<Human> user) {
        users.push_back(user);
    }
    
    void showAllUsers() {
        cout << "\n=== 所有用户 ===" << endl;
        for (size_t i = 0; i < users.size(); i++) {
            cout << i + 1 << ". " << users[i]->getName() 
                 << " (" << users[i]->getId() << ")" << endl;
        }
    }
    
    void showUnpaidUsers() {
        cout << "\n=== 未缴费名单 ===" << endl;
        bool found = false;
        for (const auto& user : users) {
            if (user->getPaymentStatus() == "未缴") {
                cout << "姓名: " << user->getName() 
                     << ", 应缴: " << user->getTotalFee() << "元" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "暂无未缴费用户" << endl;
        }
    }
    
    Human* findUserByName(const string& name) {
        for (auto& user : users) {
            if (user->getName() == name) {
                return user.get();
            }
        }
        return nullptr;
    }
    
    void initSampleData() {
        // 教工样例
        auto staff1 = make_shared<Staff>("张老师", "T001");
        staff1->addWaterReading(MeterReading("W001", 202501, 100, 120));
        staff1->addElectricReading(MeterReading("E001", 202501, 300, 350));
        staff1->addGasReading(MeterReading("G001", 202501, 50, 60));
        staff1->setPaymentStatus("已缴");
        addUser(staff1);
        
        // 学生样例
        auto student1 = make_shared<Student>("李同学", "S001");
        student1->addWaterReading(MeterReading("W002", 202501, 50, 65));  // 超过免费额度
        student1->addElectricReading(MeterReading("E002", 202501, 100, 125)); // 超过免费额度
        student1->setPaymentStatus("未缴");
        addUser(student1);
        
        // 更多样例数据...
    }
};

void showMenu() {
    cout << "\n===== 水电煤气管理系统 =====" << endl;
    cout << "1. 显示所有用户" << endl;
    cout << "2. 查询用户信息" << endl;
    cout << "3. 显示未缴费名单" << endl;
    cout << "4. 添加新用户" << endl;
    cout << "5. 录入表读数" << endl;
    cout << "6. 退出系统" << endl;
    cout << "请选择操作: ";
}

int main() {
    WaterGasSystem system;
    system.initSampleData();
    
    int choice;
    bool running = true;
    
    while (running) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                system.showAllUsers();
                break;
            }
            case 2: {
                string name;
                cout << "请输入要查询的姓名: ";
                cin >> name;
                auto user = system.findUserByName(name);
                if (user) {
                    user->showAll();
                } else {
                    cout << "未找到用户: " << name << endl;
                }
                break;
            }
            case 3: {
                system.showUnpaidUsers();
                break;
            }
            case 4: {
                string type, name, id;
                cout << "选择用户类型 (1.教工 2.学生): ";
                int typeChoice;
                cin >> typeChoice;
                
                cout << "输入姓名: ";
                cin >> name;
                cout << "输入ID: ";
                cin >> id;
                
                if (typeChoice == 1) {
                    auto staff = make_shared<Staff>(name, id);
                    system.addUser(staff);
                    cout << "教工用户添加成功!" << endl;
                } else {
                    auto student = make_shared<Student>(name, id);
                    system.addUser(student);
                    cout << "学生用户添加成功!" << endl;
                }
                break;
            }
            case 5: {
                // 这里可以扩展录入功能
                cout << "录入功能待扩展..." << endl;
                break;
            }
            case 6: {
                running = false;
                cout << "感谢使用，再见!" << endl;
                break;
            }
            default: {
                cout << "无效选择，请重新输入!" << endl;
                break;
            }
        }
    }
    
    return 0;
}
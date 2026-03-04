#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 基类：用户基本信息
class Human {
protected:
    string name, id;
    // 保存半年内的费用记录
    vector<double> feeHistory;
public:
    Human(string n, string i) : name(n), id(i) {}
    virtual void showAll() = 0; // 多态接口
    void addFee(double fee) { feeHistory.push_back(fee); }
    void showHistory() {
        cout << "用户: " << name << " ID: " << id << "\n";
        cout << "最近费用记录:\n";
        for (size_t i = 0; i < feeHistory.size(); i++) {
            cout << "第 " << i+1 << " 月: " << feeHistory[i] << " 元\n";
        }
    }
};

// 教工类：直接按单位价格计费
class Staff : public Human {
    double perFeeOfWater, perFeeOfElectric, perFeeOfGas;
public:
    Staff(string n, string i, double w, double e, double g)
        : Human(n,i), perFeeOfWater(w), perFeeOfElectric(e), perFeeOfGas(g) {}
    void showAll() override {
        cout << "教工: " << name << " ID: " << id << "\n";
        cout << "水电气单价: 水 " << perFeeOfWater << " 电 " << perFeeOfElectric << " 气 " << perFeeOfGas << "\n";
    }
    double calcFee(double waterUsed, double elecUsed, double gasUsed) {
        double fee = waterUsed*perFeeOfWater + elecUsed*perFeeOfElectric + gasUsed*perFeeOfGas;
        addFee(fee);
        return fee;
    }
};

// 学生类：有免费额度
class Student : public Human {
    double freeLimitOfWater, freeLimitOfElectric;
    double perFeeOfWater, perFeeOfElectric, perFeeOfGas;
public:
    Student(string n, string i, double w, double e, double g, double fw, double fe)
        : Human(n,i), perFeeOfWater(w), perFeeOfElectric(e), perFeeOfGas(g),
          freeLimitOfWater(fw), freeLimitOfElectric(fe) {}
    void showAll() override {
        cout << "学生: " << name << " ID: " << id << "\n";
        cout << "免费额度: 水 " << freeLimitOfWater << " 电 " << freeLimitOfElectric << "\n";
    }
    double calcFee(double waterUsed, double elecUsed, double gasUsed) {
        double fee = 0;
        fee += (waterUsed > freeLimitOfWater ? (waterUsed-freeLimitOfWater)*perFeeOfWater : 0);
        fee += (elecUsed > freeLimitOfElectric ? (elecUsed-freeLimitOfElectric)*perFeeOfElectric : 0);
        fee += gasUsed*perFeeOfGas;
        addFee(fee);
        return fee;
    }
};

int main() {
    // 初始化两个用户
    Staff s("Alice","S001",1.0,0.8,2.5);
    Student st("Bob","ST001",1.0,0.8,2.5,3.0,5.0);

    // 模拟半年数据
    for(int m=1;m<=6;m++){
        double w=2*m, e=3*m, g=1*m; // 假设用量
        cout << "\n第" << m << "月:\n";
        cout << "教工费用: " << s.calcFee(w,e,g) << "\n";
        cout << "学生费用: " << st.calcFee(w,e,g) << "\n";
    }

    cout << "\n=== 查询半年记录 ===\n";
    s.showHistory();
    st.showHistory();
    return 0;
}

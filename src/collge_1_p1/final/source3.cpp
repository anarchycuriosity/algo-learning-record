#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Human
{
    protected:
        string name,id;
        double amountOfWaterLT,amountOfElectricLT,amountOfGasLT;
        double amountOfWaterNT,amountOfElectricNT,amountOfGasNT;
    public:
        Human(string nname,string iid,
        double aamomntOfWaterLT,double aamountOfElectricLT,double aamountOfGasLT,
        double aamomntOfWaterNT, double aamountOfElectricNT,double aamountOfGasNT)
        : name(nname),id(iid),
        amountOfWaterLT(aamomntOfWaterLT),amountOfWaterNT(aamomntOfWaterNT),
        amountOfElectricLT(aamountOfElectricLT),amountOfElectricNT(aamountOfElectricNT),
        amountOfGasLT(aamountOfGasLT),amountOfGasNT(aamountOfGasNT) {}
        
        virtual void showAll() = 0;  // 整合到一个函数
};

class Staff :public Human
{
    private:
        double perFeeOfWater,perFeeOfElectric,perFeeOfGas;
    public:
        Staff(string nname,string iid,
        double aamountOfWaterLT,double aamountOfElectricLT,double aamountOfGasLT,
        double aamountOfWaterNT, double aamountOfElectricNT,double aamountOfGasNT,
        double pperFeeOfWater,double pperFeeOfElectric,double pperFeeOFGas)
        : Human( nname,iid,
         aamountOfWaterLT, aamountOfElectricLT, aamountOfGasLT,
         aamountOfWaterNT, aamountOfElectricNT,aamountOfGasNT),
         perFeeOfWater(pperFeeOfWater),perFeeOfElectric(pperFeeOfElectric),perFeeOfGas(pperFeeOFGas){}
        
        void showAll() override
        {
            cout << "name: " << name << endl;
            cout << "id: " << id << endl;

            cout << "amount of water LT: " << amountOfWaterLT << " L" << endl;
            cout << "amount of electric LT: " << amountOfElectricLT << " KWH" << endl;
            cout << "amount of gas LT: " << amountOfGasLT << " L" << endl;

            cout << "amount of water NT: " << amountOfWaterNT << " L" << endl;
            cout << "amount of electric NT: " << amountOfElectricNT << " KWH" << endl;
            cout << "amount of gas NT: " << amountOfGasNT << " L" << endl;

            cout << "cost of water: " << (amountOfWaterNT - amountOfWaterLT) * perFeeOfWater << endl;
            cout << "cost of electric: " << (amountOfElectricNT - amountOfElectricLT) * perFeeOfElectric << endl;
            cout << "cost of gas: " << (amountOfGasNT - amountOfGasLT) * perFeeOfGas << endl;
        }
};

class Student :public Human
{
    private:
        double freeLimitOfWater,freeLimitOfElectric;
        double perFeeOfWater,perFeeOfElectric,perFeeOfGas;
    public:
        Student(string nname,string iid,
        double aamountOfWaterLT,double aamountOfElectricLT,double aamountOfGasLT,
        double aamountOfWaterNT, double aamountOfElectricNT,double aamountOfGasNT,
        double pperFeeOfWater,double pperFeeOfElectric,double pperFeeOFGas,
        double ffreeLimitOfWater, double ffreeLimitOfElectric)
        : Human( nname,iid,
         aamountOfWaterLT, aamountOfElectricLT, aamountOfGasLT,
         aamountOfWaterNT, aamountOfElectricNT,aamountOfGasNT),
         perFeeOfWater(pperFeeOfWater),perFeeOfElectric(pperFeeOfElectric),perFeeOfGas(pperFeeOFGas),
         freeLimitOfWater(ffreeLimitOfWater),freeLimitOfElectric(ffreeLimitOfElectric) {}
        
        void showAll() override
        {
            cout << "name: " << name << endl;
            cout << "id: " << id << endl;

            cout << "amount of water LT: " << amountOfWaterLT << " L" << endl;
            cout << "amount of electric LT: " << amountOfElectricLT << " KWH" << endl;
            cout << "amount of gas LT: " << amountOfGasLT << " L" << endl;

            cout << "amount of water NT: " << amountOfWaterNT << " L" << endl;
            cout << "amount of electric NT: " << amountOfElectricNT << " KWH" << endl;
            cout << "amount of gas NT: " << amountOfGasNT << " L" << endl;

            if(amountOfWaterNT - amountOfWaterLT < freeLimitOfWater)
                cout << "cost of water: " << 0 << endl;
            else
                cout << "cost of water: " << (amountOfWaterNT - amountOfWaterLT - freeLimitOfWater) * perFeeOfWater << endl;

            if(amountOfElectricNT - amountOfElectricLT < freeLimitOfElectric)
                cout << "cost of electric: " << 0 << endl;
            else
                cout << "cost of electric: " << (amountOfElectricNT - amountOfElectricLT - freeLimitOfElectric) * perFeeOfElectric << endl;

            cout << "cost of gas: " << (amountOfGasNT - amountOfGasLT) * perFeeOfGas << endl;
        }
};

int diffFullMonths(int startDate, int endDate) {
    // 拆分年月日
    int startYear  = startDate / 10000;
    int startMonth = (startDate / 100) % 100;
    int startDay   = startDate % 100;

    int endYear  = endDate / 10000;
    int endMonth = (endDate / 100) % 100;
    int endDay   = endDate % 100;

    // 先算总月份差
    int months = (endYear - startYear) * 12 + (endMonth - startMonth);

    // 去掉起始月和结束月
    months -= 1;

    // 如果结果小于 0，说明输入不合理
    if (months < 0) months = 0;

    return months;
}

int main() {
    int start = 20250203;
    int end   = 20270307;

    std::cout << "完整相隔月份数: " << diffFullMonths(start, end) << std::endl;
    return 0;
}

int main()
{
   
    cout << "上一次录入数据的时间是20250203\n";
    //最初录入所有数据
    int ntMonth,quantity;
    cout << "输入现在所在时间和录入人数开始初始化\n";
    cin >> ntMonth >> quantity;
    cout << "依次输入人的类型(staff/student), 名字, 水电煤气三个表的id 现在从" 
    << ntMonth - 6 
    << "月开始输入6个月以来的查表时间 水 电 煤气表数据 每月末尾\n 上一次缴费时间 上一次缴费的水电煤气量 缴费状态 以下为输入示例:\n";
    cout << "staff kurisu 20250101 1 1 1 20250201 2 2 2 20250301 3 3 3 20250401 4 4 4 20250501 5 5 5 20250601 6 6 6 20250201 2 2 2 未缴\n";


}
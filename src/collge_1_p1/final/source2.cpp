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

int main()
{
    //最初录入所有数据
    int ntMonth,quantity;
    cout << "输入现在所在月份和录入人数开始初始化\n";
    cin >> ntMonth >> quantity;
    cout << "依次输入人的类型(staff/student), 名字, 水电煤气三个表的id 现在从" << ntMonth - 6 << "月开始输入6个月以来的水 电 煤气表数据 每月末尾加上查表时间\n 以下为输入示例:\n";
    cout << "staff kurisu 2025218651 123456 654321 1 1 1 20250102  2 2 2 20250202 3 3 3 20250304 4 4 4 20250402 5 5 5 20250502 6 6 6 20250602 \n";
}
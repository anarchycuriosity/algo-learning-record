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
        virtual void showName() = 0;
        virtual void showId() = 0;

        virtual void showAmountOfWaterLT() = 0;
        virtual void showAmountOfElectricLT() = 0;
        virtual void showAmountOfGasLT() = 0;

        virtual void showAmountOfWaterNT() = 0;
        virtual void showAmountOfElectricNT() = 0;
        virtual void showAmountOfGasNT() = 0;

        virtual void showCostOfWater() = 0;
        virtual void showCostOfElectric() = 0;
        virtual void showCostOfGas() = 0;
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
        
         void showName() {cout << "name: " << name << endl;}
         void showId() {cout << "id: " << id << endl;}

        void showAmountOfWaterLT() override{cout << "amount of water: " << amountOfWaterLT << " L" << endl;}
        void showAmountOfElectricLT() override{cout << "amount of electric: " << amountOfElectricLT << "KWH" << endl;}
        void showAmountOfGasLT() override{cout << "amount of gas: " << amountOfGasLT << "L" << endl;}

        void showAmountOfWaterNT() override{cout << "amount of water: " << amountOfWaterNT << " L" << endl;}
        void showAmountOfElectricNT() override{cout << "amount of electric: " << amountOfElectricNT << "KWH" << endl;}
        void showAmountOfGasNT() override{cout << "amount of gas: " << amountOfGasNT << "L" << endl;}

        void showCostOfWater() override
        {
            cout << "cost of water: " <<  (amountOfWaterNT - amountOfElectricLT) * perFeeOfWater << endl;
        }
        void showCostOfElectric() override
        {
            cout << "cost of electric: " << (amountOfElectricNT - amountOfElectricLT) * perFeeOfElectric << endl;
        }
        void showCostOfGas() override
        {
            cout << "cost of gas: " <<  (amountOfGasNT - amountOfGasLT) * perFeeOfGas << endl;
        }
};

class Student :public Human
{
    private:
        double freeLimitOfWater,freeLimitOfElectric;
        double perFeeOfWater,perFeeOfElectric,perFeeOfGas;
    public:
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
        
         void showName() {cout << "name: " << name << endl;}
         void showId() {cout << "id: " << id << endl;}

        void showAmountOfWaterLT() override{cout << "amount of water: " << amountOfWaterLT << " L" << endl;}
        void showAmountOfElectricLT() override{cout << "amount of electric: " << amountOfElectricLT << "KWH" << endl;}
        void showAmountOfGasLT() override{cout << "amount of gas: " << amountOfGasLT << "L" << endl;}

        void showAmountOfWaterNT() override{cout << "amount of water: " << amountOfWaterNT << " L" << endl;}
        void showAmountOfElectricNT() override{cout << "amount of electric: " << amountOfElectricNT << "KWH" << endl;}
        void showAmountOfGasNT() override{cout << "amount of gas: " << amountOfGasNT << "L" << endl;}
        
        void showCostOfWater() override
        {
            if(amountOfWaterNT - amountOfWaterLT < freeLimitOfWater)
            {
                cout << "cost of water: " << 0 << endl;
            }
            else
            {
                cout << "cost of water: " <<  (amountOfWaterNT - amountOfWaterLT - freeLimitOfWater) * perFeeOfWater << endl ;
            }
        }
        void showCostOfWater() override
        {
            if(amountOfElectricNT - amountOfElectricLT < freeLimitOfElectric)
            {
                cout << "cost of electric: " << 0 << endl;
            }
            else
            {
                cout << "cost of electric: " <<  (amountOfElectricNT - amountOfElectricLT - freeLimitOfElectric) * perFeeOfElectric << endl ;
            }
        }
        void showCostOfGas() override
        {
            cout << "cost of gas: " <<  (amountOfGasNT - amountOfGasLT) * perFeeOfGas << endl;
        }
};
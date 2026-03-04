#include <iostream>
using namespace std;

int main()
{
    int num_people;
    double each_amount;
    cin >> num_people >> each_amount;
    double first_all_cost = 0,last_all_cost = 0;
    if(each_amount <= 20)
    {
        first_all_cost = num_people * each_amount * 2;
    }
    else
    {
        first_all_cost = ( (each_amount - 20.0) * 3.5 + 40 ) * num_people;
    }

    if(first_all_cost < 1000)
    {
        last_all_cost = first_all_cost;
        cout << last_all_cost;
    }
    else
    {
        last_all_cost = 0.8 * first_all_cost;
        cout << last_all_cost;
    }
}
#include <iostream>
using namespace std;
class EvenNumber
{
    private:
        int value;
    public:
        EvenNumber()
        {
            value = 0;
        }
        EvenNumber(int v)
        {
            value = v;
        }

        int GetValue()
        {
            return value;
        }
        EvenNumber GetNext()
        {
            return EvenNumber(value + 2);
        }

        EvenNumber GetPrevious()
        {
            return EvenNumber(value - 2);
        }
};
int main()
{
    int v;
    cin >> v;
    EvenNumber e(v);
    cout << e.GetNext().GetValue() << endl;
    cout << e.GetPrevious().GetValue();
    return 0;
}
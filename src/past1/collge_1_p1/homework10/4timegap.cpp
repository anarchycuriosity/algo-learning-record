#include <iostream>
using namespace std;
class Clock
{
    private:
    int hours,minutes,seconds;
    public:
    Clock()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void setTime(int h,int m,int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void showTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void countGap(Clock clock2)
    {
        int gap =(hours - clock2.hours)*60 * 60 + (minutes - clock2.minutes)*60 + (seconds - clock2.seconds);
        if(gap > 0)
        cout << gap;
        else
        cout << -gap;
    }
};

int main()
{
    Clock clock1,clock2;
    int h1,m1,s1,h2,m2,s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    clock1.setTime(h1,m1,s1);
    clock2.setTime(h2,m2,s2);
    clock1.showTime();
    clock2.showTime();
    clock1.countGap(clock2);
    
}
#include <queue>
// qOut也就是第二个stack，主要是扮演一个临时的工具，用完要擦干净
class MyStack
{
public:
    std::queue<int> qIn;
    std::queue<int> qOut;
    MyStack()
    {
    }

    void push(int x)
    {
        qIn.push(x);
    }

    int pop()
    {
        // 因为要精确地控制剩下几个元素，所以不能用empty来判断条件了
        // queue的最新的元素不是那么好操作
        int times = 0;
        if (!qIn.empty())
        {
            times = qIn.size() - 1;
        }
        while (times--)
        {
            qOut.push(qIn.front());
            qIn.pop();
        }
        int res = qIn.front();
        qIn.pop();
        while (!qOut.empty())
        {
            qIn.push(qOut.front());
            qOut.pop();
        }
        return res;
    }

    int top()
    {
        int res = this->pop();
        while (!qOut.empty())
        {
            qIn.push(qOut.front());
            qOut.pop();
        }
        qIn.push(res);
        return res;
    }

    bool empty()
    {
        return qIn.empty() && qOut.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
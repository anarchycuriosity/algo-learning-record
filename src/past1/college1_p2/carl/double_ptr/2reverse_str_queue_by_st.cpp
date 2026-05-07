// STL中栈往往不被归类为容器，而被归类为container adapter（容器适配器）
// 在queue中有向前弹出，但vector这个容器并不具有这样的零件，它只有push_back所以如果插入就会编译错误
// STL 默认给栈和队列都用了 std::deque（双端队列）
/* std::stack 要求底层有 push_back / pop_back  vector 满足。
std::queue 要求底层有 push_back / pop_front  vector 不满足。 */

// 适配器就是通过“不提供某些接口”来强制你遵守数据结构的规则
// 所谓的协议，其实就是容器的成员函数的名字，比如push_back
// push_back在vector中叫功能接口，但在stack中叫要求接口

#include <stack>

class MyQueue
{
public:
    std::stack<int> stIn;
    std::stack<int> stOut;
    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    // 弹出队列头元素并返回他
    int pop()
    {
        // 只有在out空的时候才能导入
        if (stOut.empty())
        {
            while (!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    // 返回队列头元素不弹出
    int peek()
    {
        // 活用上一个函数
        int res = this->pop();
        stOut.push(res);
        return res;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
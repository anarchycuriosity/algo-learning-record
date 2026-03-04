
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 如果使用递归来写的话，由于双指针需要一直被下一层使用，所以作为参数，这和之前不太一样
class Solution
{
public:
    ListNode *reverse(ListNode *pre, ListNode *cur)
    {
        // 递归其一：终止条件
        if (cur == nullptr)
        {
            return pre;
        }

        // 递归其二，顺手任务
        ListNode *tmp = cur->next;
        cur->next = pre;

        // 递归其三，下探动作
        // 如果是void不需要返回值但这不是
        return reverse(cur, tmp);
    }

    // 下面这个才是题目的函数
    ListNode *reverseList(ListNode *head)
    {
        return reverse(nullptr, head);
    }
};
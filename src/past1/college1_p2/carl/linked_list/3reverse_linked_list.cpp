

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *tmp;
        while (cur)
        {
            // 保存cur的下一个节点便于每次循环结束跳转
            tmp = cur->next;
            // 改变指向
            cur->next = pre;

            // 双指针跳转
            // pre节点跳转
            pre = cur;
            // 遍历节点跳转
            cur = tmp;
        }
        return pre;
    }
};
// 我们可以使用递归的方式来写删除元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 基础情况
        // 需要先处理如果是空链表的情况
        // 当到达最后一层的时候，递归结束，然后返回
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->val == val)
        {
            // 新建节点做递归并删除旧的节点
            // 如果本节点需要被删除，则返回之后的节点
            ListNode *new_head = removeElements(head->next, val);
            delete head;
            return new_head;
        }
        else
        {
            // 如果本节点不需要被删除，则让本节点接上下一层递归的节点然后返回
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};
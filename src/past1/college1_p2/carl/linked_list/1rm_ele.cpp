
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
        // 设置一个虚拟头节点(傀儡节点)
        ListNode *dummyhead = new ListNode(0); // 节点的val大于0
        // 让虚拟头节点指向真实头节点
        dummyhead->next = head;
        // 进行删除操作:如果next是val,那么使用tmp暂存防止泄漏
        ListNode *cur = dummyhead;
        // NULL是0的宏定义,nullptr是血统纯正的指针
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                // 然后跨越next直接接到next->next,然后删除tmp
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else // 如果不等于val,那么让cur继续检查下一个
            {
                cur = cur->next;
            }
        }

        // 因为此时真实的头节点不一定是头节点,所以我们要给head赋值
        head = dummyhead->next;
        // 最后删除傀儡节点,返回head
        delete dummyhead;
        return head;
    }
};
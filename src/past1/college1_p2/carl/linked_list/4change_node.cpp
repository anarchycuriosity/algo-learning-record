struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 不能只是单纯改变节点内部的值，而是需要实际的进行节点交换
// 易错的是，操作的cur并不是正在进行交换的两个节点，而是一个旁观者
// 比如我们要操作3和4让他们交换，此时cur在2
// 如果要交换1和2，cur是傀儡头
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *cur = dummy_head;
        // 这是为了让操作的两个节点不能为空
        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            // 存储这两个节点的数据,因为我们等下要对他们的本体进行操作
            // 这两个tmp分别记录需要改动节点的接入点和出去的点
            ListNode *tmp1 = cur->next;
            ListNode *tmp2 = cur->next->next->next; // 这个next一个都不能少
            // tmp2的本身并不在本轮交换的节点之中,如果tmp2是1和2中的2的话,2的next在本轮结束应该是1
            // 这样在交换阶段就会乱套,所以tmp2一定是3,也就是本轮的不可接触者

            // 进行交换
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            cur->next->next->next = tmp2;

            // cur向后移动两位准备下一轮交换
            cur = cur->next->next;
        }
        ListNode *result = dummy_head->next;
        delete dummy_head;
        return result;
    }
};
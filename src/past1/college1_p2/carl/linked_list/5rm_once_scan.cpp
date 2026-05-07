struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 根据倒数第n个序列来删除元素并返回头指针,一趟扫描解决
// 什么是一趟扫描,就是不准回头,没有pre指针
// 之前是根据值来删除,所以扫描和删除使用一个指针cur和循环过程中的临时变量就好了
// 但是这里是链表,要知道你并不知道这个表有多长
// 但本质的工作量是一样的,只不过是把一个while循环切成了两段罢了
// 回到问题,不知道总长度,也就不知道前置需要查几个节点,但是你知道最后一个节点距离删除节点的距离
// 删除元素需要指针,遍历的指针不能回头,那我使用两个指针不就好了
// 这题其实就是固定长度滑动窗口

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *fast = dummy_head;
        ListNode *slow = dummy_head;
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        // fast需要提前多走一步,相当于按0为1来算,因为从傀儡头开始
        // 如果不多走一步,fast对应的slow刚好对准要删除的点,但我们需要slow在更前一个
        fast = fast->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummy_head->next;
    }
};
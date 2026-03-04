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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *dum1 = new ListNode(0);
        ListNode *dum2 = new ListNode(0);
        dum1->next = headA;
        dum2->next = headB;
        ListNode *cur1 = dum1;
        ListNode *cur2 = dum2;
        // 最大的问题其实是确定在相交的节点之前二者的长度差了多少,所以计算出长度,两次while是必须的
        int count1 = 0;
        int count2 = 0;
        while (cur1 != nullptr)
        {
            cur1 = cur1->next;
            count1++;
        }
        while (cur2)
        {
            cur2 = cur2->next;
            count2++;
        }
        int gap = (count1 - count2 > 0) ? count1 - count2 : count2 - count1;
        int judge = 0;
        if (count1 > count2)
        {
            judge = 1;
        }
        else if (count1 < count2)
        {
            judge = 2;
        }
        cur1 = dum1;
        cur2 = dum2;
        if (judge == 1)
        {
            while (gap--)
            {
                cur1 = cur1->next;
            }
        }
        else if (judge == 2)
        {
            while (gap--)
            {
                cur2 = cur2->next;
            }
        }

        while (cur1 != nullptr && cur2 != nullptr && cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q:为什么选择1:2这个神奇比例呢,如果选择99:100.公式不一定成立如果选择1:3,扫描可能会跳过
// 1:2中,1是node的最小单位,快相对于慢是一个一个节点进行扫描,逐个逼近,这确保数据不会遗漏

/*
x为进圈前,y为进圈到相遇,z为相遇到下一次进圈点
(x + y) * 2 = x + y + n (y + z)

两边消掉一个（x+y）: x + y  = n (y + z)

因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。

所以要求x ，将x单独放在左面：x = n (y + z) - y ,
我们此时想象一个index1从头出发,想象一个index2从相遇点出发,index2至少绕完那圈的剩余部分和index1相遇
y+z是一圈,如果n更大,那就是绕更多圈的事情,最终依然是在入口处相遇,而且x大于等于剩余部分.
*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 第一步是双指针追逐找到相遇的点(不需要再额外设置变量了,if判断找到即可 )
        // 慢指针入圈的时候,快指针一定在圈中等着它.
        // 同一起点出发,如果他们之间的速度差大于慢指针本身,尚且可以在慢走完一圈前相遇,何况快指针在圈中等着
        // ListNode *dum = new ListNode(0);
        ListNode *fast = head;
        ListNode *slow = head;
        // 好吧其实不需要傀儡头了否则会产生偏移
        // 不能在while写退出条件是等于
        while (fast != nullptr && fast->next != nullptr) // 防御性编程
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *ind1 = head; // 不能从傀儡头开始遍历
                ListNode *ind2 = fast;
                while (ind1 != ind2)
                {
                    ind1 = ind1->next;
                    ind2 = ind2->next;
                }
                return ind2; // 返回环的入口
            }
        }
        return nullptr;
    }
};
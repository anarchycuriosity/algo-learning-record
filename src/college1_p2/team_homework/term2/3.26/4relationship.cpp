#include <bits/stdc++.h>
// 废弃
class node
{
public:
    int index;
    node *next;
    node(int _index)
    {
        index = _index;
        next = nullptr;
    }
};
class linked_list
{
public:
    linked_list(node *_node)
    {
        node *dummy = new node(0);
        head = dummy;
        head->next = _node;
    }
    linked_list()
    {
        node *dummy = new node(0);
        head = dummy;
        head->next = nullptr;
    }
    void merge(node *_node)
    {
        node *cur = head;
        while (cur->next != head && cur->next != nullptr)
        {
            if (cur->next == _node)
            {
                return;
            }
            cur = cur->next;
        }

        cur->next = _node;
        _node->next = head;
    }
    node *head;
};
// n个人，m对关系，p个询问
int main()
{
    int n, m, p;
    std::cin >> n >> m >> p;
    linked_list ll;
    std::vector<node> nodes;
    for (int i = 1; i <= n; i++)
    {
        nodes.push_back({i});
    }
    for (int i = 0; i < m; i++)
    {
        int rel1, rel2;
        std::cin >> rel1 >> rel2;
        ll.merge(&nodes[rel1]);
        ll.merge(&nodes[rel2]);
    }
    for (int i = 0; i < p; i++)
    {
    }
}
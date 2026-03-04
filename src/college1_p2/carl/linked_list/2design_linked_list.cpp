#include <vector>
#include <iostream>

class MyLinkedList
{

public:
    // 首先需要定义链表节点结构体
    struct Linked_node
    {
        int val;
        Linked_node *next;
        Linked_node(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList()
    {
        _dummy_head = new Linked_node(0);
        _size = 0;
    }

    // 根据索引查找链表元素，如果越界就返回-1
    // 要找index我们首先需要找到index-1
    int get(int index)
    {
        if (index >= _size || index < 0)
        {
            return -1;
        }
        Linked_node *cur = _dummy_head->next;
        while (index--) // 这里不能是--index，否则死循环,非0即是真，无法查找头节点
        {
            cur = cur->next; // 我们不断往后更新cur去找节点
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        Linked_node *aim = new Linked_node(val);
        aim->next = _dummy_head->next;
        // 这里还要记得移动dummy_head
        _dummy_head->next = aim;
        _size++; // 增加长度
    }

    void addAtTail(int val)
    {
        Linked_node *new_node = new Linked_node(val);
        Linked_node *cur = _dummy_head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = new_node;
        _size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > _size)
        {
            return;
        }
        // 如果index小于0视为0
        if (index < 0)
        {
            index = 0;
        }
        Linked_node *new_node = new Linked_node(val);
        Linked_node *cur = _dummy_head;
        while (index--)
        {
            cur = cur->next;
        }
        new_node->next = cur->next;
        //_dummy_head->next = new_node;
        cur->next = new_node;
        _size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= _size)
        {
            return;
        }
        Linked_node *cur = _dummy_head;
        while (index--)
        {
            cur = cur->next;
        }
        Linked_node *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // delete命令指示释放了tmp指针原本所指的那部分内存，
        // 被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        // 如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        // 如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp = nullptr;
        _size--;
    }

private:
    Linked_node *_dummy_head;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
# include <iostream>
#include <stdlib.h>
using namespace std;

// 定义双链表节点结构体
struct Node {
    int data; 
    Node* ptr; 
    Node(int x) : data(x), ptr(NULL) {} 
};

// 定义双链表类
class DoublyLinkedList {
    Node* head; // 头节点
    Node* tail; // 尾节点
    int size; // 链表长度
public:
    // 构造函数，初始化空链表
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    // 按位置查找节点，返回节点指针，如果位置无效，返回NULL
    Node* find(int pos) {
        if (pos < 0 || pos >= size) return NULL; 
        Node* cur = head;
        Node* prev = NULL; 
        Node* next;
        for (int i = 0; i < pos; i++) { 
            next = (Node*)((uintptr_t)cur->ptr ^ (uintptr_t)prev); 
            prev = cur; 
            cur = next; 
        }
        return cur; 
    }

    // 在指定位置插入节点，如果位置无效，返回false，否则返回true
    bool insert(int pos, int x) {
        if (pos < 0 || pos > size) return false;
        Node* node = new Node(x);
        if (size == 0) {
            head = node;
            tail = node;
        } else if (pos == 0) {
            node->ptr = head;
            head->ptr = (Node*)((uintptr_t)head->ptr ^ (uintptr_t)node);
            head = node;
        } else if (pos == size) {
            node->ptr = tail;
            tail->ptr = (Node*)((uintptr_t)tail->ptr ^ (uintptr_t)node);
            tail = node;
        } else {
            Node* prev = find(pos - 1);
            Node* next = (Node*)((uintptr_t)prev->ptr ^ (uintptr_t)find(pos));
            node->ptr = (Node*)((uintptr_t)prev ^ (uintptr_t)next);
            prev->ptr = (Node*)((uintptr_t)prev->ptr ^ (uintptr_t)next ^ (uintptr_t)node);
            next->ptr = (Node*)((uintptr_t)next->ptr ^ (uintptr_t)prev ^ (uintptr_t)node);
        }
        size++; 
        return true;
    }

    // 删除指定位置的节点，如果位置无效，返回false，否则返回true
    bool remove(int pos) {
        if (pos < 0 || pos >= size) return false;
        Node* node = find(pos);
        if (size == 1) {
            head = NULL;
            tail = NULL;
        } else if (pos == 0) { 
            head = (Node*)((uintptr_t)node->ptr ^ (uintptr_t)NULL);
            head->ptr = (Node*)((uintptr_t)head->ptr ^ (uintptr_t)node);
        } else if (pos == size - 1) { 
            tail = (Node*)((uintptr_t)node->ptr ^ (uintptr_t)NULL);
            tail->ptr = (Node*)((uintptr_t)tail->ptr ^ (uintptr_t)node);
        } else {
            Node* prev = find(pos - 1);
            Node* next = (Node*)((uintptr_t)node->ptr ^ (uintptr_t)prev);
            prev->ptr = (Node*)((uintptr_t)prev->ptr ^ (uintptr_t)node ^ (uintptr_t)next);
            next->ptr = (Node*)((uintptr_t)next->ptr ^ (uintptr_t)node ^ (uintptr_t)prev); 
        }
        delete node; // 释放节点内存
        size--;
        return true; 
    }

    int getsize() { // 获取链表长度
        return size;
    }
};
int main() {
    DoublyLinkedList dll; // 创建一个空的双链表
    cout << "插入10个节点到链表尾部" << endl;
    for (int i = 0; i < 10; i++) {
        dll.insert(dll.getsize(), i); // 在链表尾部插入节点
    }
    cout << "链表长度为：" << dll.getsize() << endl;
    cout << "链表头节点的数据为：" << dll.find(0)->data << endl;
    cout << "链表尾节点的数据为：" << dll.find(dll.getsize()-1)->data << endl;
    cout << "在链表中间位置插入一个节点，数据为100" << endl;
    dll.insert(dll.getsize() / 2, 100); // 在链表中间位置插入一个节点
    cout << "链表长度为：" << dll.getsize() << endl;
    cout << "链表中间节点的数据为：" << dll.find(dll.getsize() / 2)->data << endl;
    cout << "删除链表头节点" << endl;
    dll.remove(0); // 删除链表头节点
    cout << "链表长度为：" << dll.getsize() << endl;
    cout << "链表头节点的数据为：" << dll.find(0)->data << endl;
    cout << "删除链表尾节点" << endl;
    dll.remove(dll.getsize() - 1); // 删除链表尾节点
    cout << "链表长度为：" << dll.getsize() << endl;
    cout << "链表尾节点的数据为：" << dll.find(dll.getsize()-1)->data << endl;
    cout << "删除链表中间节点" << endl;
    dll.remove(dll.getsize() / 2); // 删除链表中间节点
    cout << "链表长度为：" << dll.getsize() << endl;
    cout << "遍历链表，打印所有节点的数据" << endl;
    Node* cur = dll.find(0); // 当前节点
    Node* prev = NULL; // 前一个节点
    Node* next; // 后一个节点
    while (cur != NULL) { // 遍历链表，直到当前节点为空
        cout << cur->data << " ";
        next = (Node*)((uintptr_t)cur->ptr ^ (uintptr_t)prev); // 用异或运算得到后一个节点的地址
        prev = cur; // 更新前一个节点
        cur = next; // 更新当前节点
    }
    cout << endl;
    system("pause"); // 暂停系统
    return 0;
}
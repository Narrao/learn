#include<iostream>
#include <stdlib.h>
using namespace std;
template<typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(T x):data(x),next(NULL),prev(NULL){}
};
template<typename T>
class DoublyLinkedList
{
    Node<T>* head;
    int size;
public:
    DoublyLinkedList():head(NULL),size(0){}
    DoublyLinkedList(int n)
    {
        T x;
        cin >> x;
        Node<T>* temp = new Node<T>(x);
        head = temp;
        for(int i=1;i<n;i++)
        {
            cin >> x;
            Node<T>* temp2 = new Node<T>(x);
            temp->next = temp2;
            temp2->prev = temp;
            temp = temp2;
        }
        temp->next = NULL;
        size=n;
    }
    DoublyLinkedList(DoublyLinkedList<T>& a)
    {
        Node<T>* temp = a.head;
        Node<T>* temp2 = new Node<T>(temp->data);
        head = temp2;
        temp = temp->next;
        while(temp!=NULL)
        {
            Node<T>* temp3 = new Node<T>(temp->data);
            temp2->next = temp3;
            temp3->prev = temp2;
            temp2 = temp3;
            temp = temp->next;
        }
        temp2->next = NULL;
        size = a.size;
    }
    // 将两个有序链表合并成一个新的有序链表允许重复数据
    static DoublyLinkedList<T>* merge1(DoublyLinkedList<T>* a,DoublyLinkedList<T>* b)
    {
        Node<T>* i = a->head;
        Node<T>* j = b->head;
        Node<T>* k = NULL;
        DoublyLinkedList<T>* c = new DoublyLinkedList<T>();
        if(i->data < j->data)
        {
            c->head = i;
            k = i;
            i = i->next;
        }
        else
        {
            c->head = j;
            k = j;
            j = j->next;
        }
        while(i!=NULL && j!=NULL)
        {
            if(i->data < j->data)
            {
                k->next = i;
                i->prev = k;
                k = i;
                i = i->next;
            }
            else
            {
                k->next = j;
                j->prev = k;
                k = j;
                j = j->next;
            }
        }
        if(i!=NULL)
        {
            k->next = i;
            i->prev = k;
        }
        else
        {
            k->next = j;
            j->prev = k;
        }
        return c;
    }
    // 要求合并后的有序链表无重复数据
    static DoublyLinkedList<T>* merge2(DoublyLinkedList<T>* a,DoublyLinkedList<T>* b)
    {
        Node<T>* i = a->head;
        Node<T>* j = b->head;
        Node<T>* k = NULL;
        DoublyLinkedList<T>* c = new DoublyLinkedList<T>();
        if(i->data < j->data)
        {
            c->head = i;
            k = i;
            i = i->next;
        }
        else if(i->data > j->data)
        {
            c->head = j;
            k = j;
            j = j->next;
        }
        else
        {
            c->head = i;
            k = i;
            i = i->next;
            j = j->next;
        }
        while(i!=NULL && j!=NULL)
        {
            if(i->data < j->data)
            {
                if(i->data != k->data)
                {
                    k->next = i;
                    i->prev = k;
                    k = i;
                }
                i = i->next;
            }
            else
            {
                if(j->data != k->data)
                {
                    k->next = j;
                    j->prev = k;
                    k = j;
                }
                j = j->next;
            }
        }
        while(i!=NULL)
        {
            if(i->data != k->data)
            {
                k->next = i;
                i->prev = k;
                k = i;
            }
            i = i->next;
        }
        while(j!=NULL)
        {
            if(j->data != k->data)
            {
                k->next = j;
                j->prev = k;
                k = j;
            }
            j = j->next;
        }
        return c;
    }
    // 要求合并后的链表为非递增的有序链表
    static DoublyLinkedList<T>* merge3(DoublyLinkedList<T>* a,DoublyLinkedList<T>* b)
    {
        Node<T>* i = a->head;
        Node<T>* j = b->head;
        Node<T>* k = NULL;
        Node<T>* temp = NULL;
        DoublyLinkedList<T>* c = new DoublyLinkedList<T>();
        if(i->data<j->data)
        {
            c->head = i;
            k = i;
            i = i->next;
            k -> next = NULL;
        }
        else
        {
            c->head = j;
            k = j;
            j = j->next;
            k -> next = NULL;
        }
        while(i!=NULL && j!=NULL)
        {
            if(i->data<j->data)
            {
                i->prev = NULL;
                k->prev = i;
                temp = i;
                i = i->next;
                temp -> next = k;
                k = k->prev;
                c->head = k;
            }
            else
            {
                j->prev = NULL;
                k->prev = j;
                temp = j;
                j = j->next;
                temp -> next = k;
                k = k->prev;
                c->head = k;
            }
        }
        while(i!=NULL)
        {
            i->prev = NULL;
            k->prev = i;
            temp = i;
            i = i->next;
            temp -> next = k;
            k = k->prev;
            c->head = k;
        }
        while(j!=NULL)
        {
            j->prev = NULL;
            k->prev = j;
            temp = j;
            j = j->next;
            temp -> next = k;
            k = k->prev;
            c->head = k;
        }
        return c;
    }
    void print()
    {
        Node<T>* temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    int n,m;
    cout<< "请输入链表a和b的长度：";
    cin >> n >> m;
    cout << "请输入链表a的数据：";
    DoublyLinkedList<int>* a1 = new DoublyLinkedList<int>(n);
    cout << "请输入链表b的数据：";
    DoublyLinkedList<int>* b1 = new DoublyLinkedList<int>(m);
    DoublyLinkedList<int>* a2 = new DoublyLinkedList<int>(*a1);
    DoublyLinkedList<int>* b2 = new DoublyLinkedList<int>(*b1);
    DoublyLinkedList<int>* a3 = new DoublyLinkedList<int>(*a1);
    DoublyLinkedList<int>* b3 = new DoublyLinkedList<int>(*b1);
    cout<<"链表a：";
    a1->print();
    cout<<"链表b：";
    b1->print();
    DoublyLinkedList<int>* c1 = DoublyLinkedList<int>::merge1(a1,b1);
    DoublyLinkedList<int>* c2 = DoublyLinkedList<int>::merge2(a2,b2);
    DoublyLinkedList<int>* c3 = DoublyLinkedList<int>::merge3(a3,b3);
    cout<<"合并后允许重复的链表：";
    c1->print();
    cout<<"合并后无重复的链表：";
    c2->print();
    cout<<"合并后为非递增有序链表的链表：";
    c3->print();

    system("pause");
    return 0;
}
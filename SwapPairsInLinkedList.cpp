#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

int main() {
    char c;
    ListNode* head = nullptr;
    ListNode* p = head;
    while(getchar()!='[');
    while((c=getchar())!=']') {
        if (c == ',') {
            continue;
        } else if (c >= '0' && c <= '9') {
            if (head == nullptr) {
                head = new ListNode(c - '0');
                p = head;
            } else {
                p->next = new ListNode(c - '0');
                p = p->next;
            }
        }
    }
    ListNode* newHead = swapPairs(head);
    cout << '[';
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << ']' << endl;
    system("pause");
    return 0;
}
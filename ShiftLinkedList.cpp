#include<iostream>
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
        this->value = value;
        next = nullptr;
    }
};

LinkedList* shiftLinkedList(LinkedList* head, int k) 
{
    LinkedList* p = head;
    int n = 1;
    LinkedList* pre = head;
    while(p->next != nullptr)
    {
        if( n > k)
        {
            pre = pre->next;
        }
        
        p = p->next;
        n++;
        if(p->next==nullptr && n < k)
        {
            p = head;
            n++;
        }
    }
    if(n== k)
    {
        return head;
    }
    cout << "Pre Value: " << pre->value << endl;
    p->next = head;
    head = pre->next;
    pre->next = nullptr;
    p = nullptr;
    return head;
}
int main()
{
    LinkedList* head = new LinkedList(0);
    head->next = new LinkedList(1);
    head->next->next = new LinkedList(2);
    head->next->next->next = new LinkedList(3);
    head->next->next->next->next = new LinkedList(4);
    head->next->next->next->next->next = new LinkedList(5);
    head = shiftLinkedList(head, 14);
    while(head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    return 0;
}
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
    int n;
    (k > 0)? n = 1: n = -1;
    LinkedList* pre = head;
    while(p->next != nullptr)
    {
        cout << "in loop, n is: " << n << "\n";
        if(k > 0)
        {
            cout << "positive\n";
            if( n > k)
            {
                cout << "pre node find\n";
                (pre->next == nullptr)? pre = head: pre = pre->next;
            }
            n++;
        }
        else
        {
            cout << "Negative\n";
            if(n != k)
            {
                cout << "Checking Pre\n";
                if(pre->next == nullptr)
                {
                    cout << "Pre Reached null reseting it\n";
                    pre = head;
                }
                else
                {
                    cout << "Go with the flow pre->value: " << pre->value << "\n";
                    pre = pre->next;
                }
                n--;
            }
            
        }
        p = p->next;
        if(p->next==nullptr)
        {
            cout << "reach end resetting head\n";
            
            if( k > 0)
            {
                if(n < k)
                {
                    n++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(n > k)
                {
                    cout << "n is: " << n << endl;
                    //n--;
                }
                else
                {
                    break;
                }
            }
            p = head;
        }
    }
    cout << "Hello\n";
    if(n== k && k > 0)
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
    head = shiftLinkedList(head, -14);
    while(head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    return 0;
}
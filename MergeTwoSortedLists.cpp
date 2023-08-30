#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
    if(list1 == nullptr)
    {
        return list2;
    }
    if(list2 == nullptr)
    {
        return list1;
    }
    ListNode* p1 = list1;
    ListNode* p2 = list2;
    ListNode* p1Temp;
    ListNode* p2Temp;
    ListNode* phead2 = nullptr;
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->val < p2->val)
        {
            cout << "p1->value: " << p1->val << endl;
            p1Temp = p1;
            p1 = p1->next;
            p1Temp->next = p2;
            // p2Temp = p1Temp;
            if(phead2!=nullptr)
            {
                p2Temp->next = p1Temp;
            }
            else if(p2 == list2 && phead2 == nullptr)
            {
                phead2 = p1Temp;
                cout << "pHead2: " << phead2->val << endl;
            }
            else if(p2 != list2)
            {
                p2Temp->next = p1Temp;
            }
            p2Temp = p1Temp;
            cout << "p2Temp: " << p2Temp->val << endl;
        }
        else
        {
            p2Temp = p2;
            p2 = p2->next;
        }
    }
    if(p2Temp->next == nullptr)
    {
        p2Temp->next = p1;
    }
    if(phead2 == nullptr)
    {
        return list2;
    }
    return phead2;
    
}
int main()
{
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    ListNode* res = mergeTwoLists(list1, list2);
    while(res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
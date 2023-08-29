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
    ListNode* phead2;
    while(p1 != nullptr && p2 != nullptr)
    {
        if(p1->val < p2->val)
        {
            p1Temp = p1;
            p1 = p1->next;
            p1Temp->next = p2;
            // p2Temp = p1Temp;
            if(p2!=list2)
            {
                 p2Temp->next = p1Temp;
                 p2Temp = p1Temp;
            }
            else
            {
                phead2 = p1Temp;
            }
        }
        else
        {
            p2Temp = p2;
            p2 = p2->next;
        }
    }
    return phead2;
    
}
int main()
{
    ListNode* list1 = new ListNode(4);
    list1->next = new ListNode(6);
    list1->next->next = new ListNode(7);
    list1->next->next->next = new ListNode(7);
    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(8);
    list2->next->next = new ListNode(9);
    ListNode* res = mergeTwoLists(list1, list2);
    while(res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
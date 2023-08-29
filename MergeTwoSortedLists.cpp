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
    while(p1 != nullptr || p2 != nullptr)
    {
        if(p1->val >= p2->val && p1 != nullptr)
        {
            p1 = p1->next;
        }
        else
        {
            
        }
    }
    
}
int main()
{
    
    return 0;
}
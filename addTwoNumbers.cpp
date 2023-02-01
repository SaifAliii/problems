/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* prev = q;
        int remainder = 0;
        int sum;
        while (p != nullptr && q != nullptr)
        {
            if (q->next == nullptr && p->next != nullptr)
            {
                q->next = new ListNode(0);
            }
            else if (p->next == nullptr)
            {
                p->next = new ListNode(0);
            }
            sum = (p->val + q->val + remainder);
            remainder = sum / 10;
            sum = sum % 10;
            q->val = sum;
            if (q != nullptr)
            {
                prev = q;
                q = q->next;
            }
            if (p != nullptr)
            {
                p = p->next;
            }
        }
        if (remainder != 0)
        {
            prev->next = new ListNode(remainder);
        }
        return l2;
    }
};
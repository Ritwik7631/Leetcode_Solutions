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
        
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int c = 0;

        while(l1 != nullptr || l2 != nullptr || c != 0)
        {
            int a=0,b=0;

            if(l1 != nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            } 

            if(l2 != nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }

            int total = a + b + c;

            ListNode* curr = new ListNode(total%10);

            c = total / 10;
            
            tail->next = curr;
            tail = tail->next;
        }

        return dummy.next;
    }
};
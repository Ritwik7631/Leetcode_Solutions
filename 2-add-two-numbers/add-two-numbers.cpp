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
        ListNode* anshead = new ListNode(0);
        ListNode* finalans = anshead;

        ListNode* mover1 = l1;
        ListNode* mover2 = l2;
        
        int carry = 0;

        while(mover1 != nullptr || mover2 != nullptr || carry != 0)
        {   
            int a = 0, b = 0;
            if(mover1 != nullptr) a = mover1->val;
            if(mover2 != nullptr) b = mover2->val;

            int total = (carry + a + b);
            carry = total / 10;

            ListNode* curr = new ListNode(total % 10);
            anshead->next = curr;

            anshead = anshead->next;

            if(mover1 != nullptr) mover1 = mover1->next;
            if(mover2 != nullptr) mover2 = mover2->next;
        }

        return finalans->next;
    }
};
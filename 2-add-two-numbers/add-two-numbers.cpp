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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carryover = 0;

        ListNode* ans = NULL;
        ListNode* temp = ans;

        while(temp1 != NULL || temp2 != NULL)
        {
            ListNode* current = new ListNode();

            if(temp1 != NULL && temp2 != NULL)
            {
                current->val = (temp1->val + temp2->val + carryover)%10;

                if(temp1->val + temp2->val + carryover >= 10) carryover = 1;
                else carryover = 0;

            }
            else if(temp1 != NULL && temp2 == NULL)
            {
                current->val = (temp1->val + 0 + carryover)%10;
                if(temp1->val + carryover >= 10) carryover = 1;
                else carryover = 0;
            }
            else
            {
                current->val = (temp2->val + 0 + carryover)%10;
                if(temp2->val + carryover >= 10) carryover = 1;
                else carryover = 0;
            }

            if(temp != NULL) temp->next = current;
            else ans = current;
            temp = current;

            if(temp1 != NULL) temp1 = temp1->next;
            if(temp2 != NULL) temp2 = temp2->next;
        }

        if(carryover == 1)
        {
            ListNode* last = new ListNode();
            last->val = 1;
            temp->next = last;
        }

        return ans;
    }
};
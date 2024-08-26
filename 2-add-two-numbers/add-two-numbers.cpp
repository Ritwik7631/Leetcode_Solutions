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

        while(temp1 != NULL || temp2 != NULL || carryover != 0)
        {
            ListNode* current = new ListNode();
            int cur = 0;
            if(temp1 != NULL) cur += temp1->val;
            if(temp2 != NULL) cur += temp2->val;
            cur += carryover;
            carryover = 0;
            current->val = cur%10;
            carryover = cur/10;

            if(temp != NULL) temp->next = current;
            else ans = current;
            temp = current;

            if(temp1 != NULL) temp1 = temp1->next;
            if(temp2 != NULL) temp2 = temp2->next;
        }

        return ans;
    }
};
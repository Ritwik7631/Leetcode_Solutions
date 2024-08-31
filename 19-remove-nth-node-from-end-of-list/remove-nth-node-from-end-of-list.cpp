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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x = 1;

        ListNode* mover = head;

        while(mover != NULL)
        {
            mover = mover->next;
            x++;
        }

        x--;

        mover = head;
        if(x >= n+1)
        {
            while(x > n+1)
            {
                mover = mover->next;
                x--;
            }

            ListNode* dupl = mover;

            dupl = dupl->next;
            dupl = dupl->next;

            mover->next = dupl;

            return head;            
        }
        else
        {
            head = head->next;
            return head;
        }

        return NULL;
        
    }
};
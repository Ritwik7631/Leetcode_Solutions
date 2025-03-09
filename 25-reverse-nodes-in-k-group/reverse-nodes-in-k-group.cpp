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
    ListNode* newhead = nullptr;

    void fn(ListNode* curr, ListNode* b)
    {
        if(curr == b)
        {
            newhead = b;
            return;
        }

        fn(curr->next, b);

        curr->next->next = curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;

        ListNode* anshead = nullptr;
        ListNode* tail = anshead;

        ListNode* mover = head;
        
        int count = 1;
        ListNode* left;
        ListNode* right;
        while(mover != nullptr)
        {
            if(count == 1)
            {
                left = mover;
                mover = mover->next;
            }
            else if(count == k)
            {
                right = mover;
                ListNode* after = right->next;
                right->next = nullptr;

                fn(left, right);

                left->next = nullptr;

                if(anshead == nullptr)
                {
                    anshead = newhead;
                }
                else
                {
                    tail->next = newhead;    
                }

                tail = left;
                count = 1;
                mover = after;
                continue;
            }
            else
            {
                mover = mover->next;
            }

            count++;
        }

        if(count != 1)
        {
            if(anshead == nullptr)
            {
                anshead = left;
            }
            else
            {
                tail->next = left;
            }
        }

        return anshead;
    }
};
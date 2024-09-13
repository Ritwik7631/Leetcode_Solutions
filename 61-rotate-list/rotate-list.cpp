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
    ListNode* rotateRight(ListNode* head, int k) {
    //     ListNode* last = head;
    //     int len = 1;
    //     while(last->next != nullptr)
    //     {
    //         last = last->next;
    //         len++;
    //     }

    //     k = k%len;

    //     len = len-k;

    //     ListNode* newhead = head;
    //     ListNode* x = nullptr;

    //     while(len >= 0)
    //     {
    //         len--;
    //         x = newhead;
    //         newhead = newhead->next;
    //     }

    //     x->next = nullptr;
    //     last->next = head;

    //     return newhead;
        if(head == nullptr || head->next == nullptr) return head;
        if(k == 0) return head;

        ListNode* mover = head;
        int len = 1;

        while(mover->next != nullptr)
        {
            mover = mover->next;
            len++;
        }

        mover->next = head;

        k = k%len;
        
        len = len-k;

        mover = head;

        while(len > 0)
        {
            len--;

            if(len == 0)
            {
                ListNode* newhead = mover->next;
                mover->next = nullptr;
                return newhead;
            }
            else
            {
                mover = mover->next;
            }
        }

        return nullptr;
    }
};
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
    ListNode* newhead;
    ListNode* tail;

    void fn(ListNode* curr, ListNode* b)
    {
        if(curr == b)
        {
            newhead = b;
            return;
        }
         
        fn(curr->next, b);

        curr->next->next = curr;

        tail = curr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* l;
        ListNode* r;
        ListNode* prev = nullptr;

        ListNode* mover = head;

        int count = 0;
        while(mover != nullptr)
        {
            count++;

            if(count == left-1) prev = mover;

            if(count == left)
            {
                l = mover;
            }

            if(count == right)
            {
                r = mover;
                break;
            }

            mover = mover->next;
        }

        ListNode* after = r->next;
        r->next = nullptr;

        fn(l,r);

        l->next = nullptr;

        if(left == 1)
        {
            tail->next = after;
            return newhead;
        }

        prev->next = newhead;
        tail->next = after;

        return head;
    }
};
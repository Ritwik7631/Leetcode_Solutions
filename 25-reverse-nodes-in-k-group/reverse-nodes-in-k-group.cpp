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
    void rv(ListNode* a, ListNode* b)
    {
        if(a->next == b)
        {
            b->next = a;
            return;
        }

        rv(a->next, b);

        a->next->next = a;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        ListNode* anshead = nullptr;

        ListNode* currend;

        int s = 0;
        int e = k-1;

        ListNode* start = nullptr;
        ListNode* end = nullptr;

        ListNode* mover = head;

        int c = -1;

        while(mover != nullptr)
        {
            c++;

            if(c == s)
            {
                start = mover;
            }
            
            if(c == e)
            {
                end = mover;

                ListNode* nxt = mover->next;

                rv(start, end);

                start->next = nxt;

                if(anshead == nullptr)
                {
                    anshead = end;
                    currend = start;
                }
                else
                {
                    currend->next = end;
                    currend = start;
                }

                c = -1;

                mover = nxt;
                continue;
            }

            mover = mover->next;
        }

        if(anshead == nullptr) return head;

        return anshead;
    }
};
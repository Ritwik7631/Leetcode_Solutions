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
            a->next = nullptr;
            return;
        }
        rv(a->next, b);
        a->next->next = a;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        
        ListNode* anshead = nullptr;
        ListNode* prevTail = nullptr;  // To connect previous reversed group
        
        ListNode* mover = head;
        int c = -1;
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        int s = 0;
        int e = k - 1;
        
        while(mover != nullptr)
        {
            c++;
            if(c % k == s)
                start = mover;
            if(c % k == e)
            {
                end = mover;
                ListNode* nxt = mover->next;
                
                rv(start, end);      // Reverse current group
                start->next = nxt;   // Connect reversed group tail to next part
                
                if(prevTail != nullptr)
                    prevTail->next = end;  // Connect previous group to current group
                else
                    anshead = end;         // First reversed group becomes the new head
                
                prevTail = start;          // Update previous tail for next reversal
                
                // Jump mover ahead to the next group's start and reset counter
                mover = nxt;
                c = -1;  // reset counter for the new group
                continue;  // skip the mover = mover->next below
            }
            mover = mover->next; // Advance pointer normally if group not complete
        }
        
        return anshead ? anshead : head;
    }
};

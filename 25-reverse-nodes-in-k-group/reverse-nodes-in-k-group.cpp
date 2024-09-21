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
    void fn(ListNode* curr, ListNode*& ans)
    {
        if(curr == nullptr || curr->next == nullptr)
        {
            ans = curr;
            return;
        }

        ListNode* nxt = curr->next;
        fn(nxt, ans);
        nxt->next = curr;
        curr->next = nullptr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* d = nullptr;

        ListNode* mover = head;
        ListNode* ans = nullptr;
        int counter = 0;

        while(mover != nullptr)
        {
            counter++;

            if(counter == 1) b = mover;

            if(counter == k)
            {
                d = mover->next;

                mover->next = nullptr; // remember to update mover

                ListNode* c = nullptr;
    
                fn(b, c);

                if (ans == nullptr) {
                    ans = c;
                }

                if(a != nullptr) a->next = c;

                b->next = d;

                counter = 0;
                a = b;
                mover = d;
            }
            else
            {
                mover = mover->next;
            } 
        }

        if (counter > 0 && a != nullptr) {
            a->next = b; // `b` is the start of the remaining nodes
        }

        return ans;



    }
};
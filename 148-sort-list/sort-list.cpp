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
    ListNode* mergesort(ListNode* a, ListNode* b)
    {
        ListNode* mover1 = a;
        ListNode* mover2 = b;
        ListNode* ans = nullptr;
        ListNode* headans;

        while(mover1 != nullptr && mover2 != nullptr)
        {
            if(mover1->val < mover2->val)
            {
                if(ans == nullptr)
                {
                    ans = mover1;
                    headans = mover1;
                }
                else
                {
                    ans->next = mover1;
                    ans = ans->next;
                }

                mover1 = mover1->next;
            }
            else
            {
                if(ans == nullptr)
                {
                    ans = mover2;
                    headans = mover2;
                }
                else
                {
                    ans->next = mover2;
                    ans = ans->next;
                }

                mover2 = mover2->next;
                
            }
        }

        while(mover1 != nullptr)
        {
            if(ans == nullptr)
            {
                ans = mover1;
                headans = mover1;
            }
            else
            {
                ans->next = mover1;
                ans = ans->next;
            }

            mover1 = mover1->next;
        }

        while(mover2 != nullptr)
        {
            if(ans == nullptr)
            {
                ans = mover2;
                headans = mover2;
            }
            else
            {
                ans->next = mover2;
                ans = ans->next;
            }

            mover2 = mover2->next;
        }

        return headans;
    }

    ListNode* fn(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* p1 = head;
        ListNode* p2 = head;

        while(p2 != nullptr && p2->next != nullptr && p2->next->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode* a = head;
        ListNode* b = p1->next;

        p1->next = nullptr;

        ListNode* c = fn(a);
        ListNode* d = fn(b);

        ListNode* ans = mergesort(c,d);

        return ans;
    }

    ListNode* sortList(ListNode* head) {
        return fn(head);
    }
};
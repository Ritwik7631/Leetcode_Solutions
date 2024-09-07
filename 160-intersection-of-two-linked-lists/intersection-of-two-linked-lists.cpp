/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0;
        int lenb = 0;

        ListNode* mover1 = headA;
        ListNode* mover2 = headB;

        while(mover1->next != nullptr)
        {
            mover1 = mover1->next;
            lena++;
        }

        while(mover2->next != nullptr)
        {
            mover2 = mover2->next;
            lenb++;
        }

        mover1 = headA;
        mover2 = headB;

        int offset = lenb-lena;

        for(int i = 0; i < abs(offset); i++)
        {
            if(offset < 0)
            {
                mover1 = mover1->next;
            }
            else
            {
                mover2 = mover2->next;
            }
        }

        while(mover1 != nullptr && mover2 != nullptr)
        {
            if(mover1 != mover2)
            {
                mover1 = mover1->next;
                mover2 = mover2->next;
            }
            else
            {
                return mover1;
            }
        }

        return nullptr;        
    }
};
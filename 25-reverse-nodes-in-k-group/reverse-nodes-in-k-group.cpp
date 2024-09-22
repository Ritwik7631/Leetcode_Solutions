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
    void fn(ListNode* curr, ListNode** ans)
    {  
        if(curr->next == nullptr)
        {
            *ans = curr;
            // cout << "base condition: " << curr->val << endl;
            return;
        }

        fn(curr->next, ans);

        curr->next->next = curr;  
    }

    /*
    fn(1,1)  
        fn(2,1)
            fn(3,1) 
                fn(4,1) 
                    fn(5,1) head = 5 
    
    
    */

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* mover = head;

        int counter = 0;
        ListNode* temphead = nullptr;
        ListNode* prevhead = nullptr;
        ListNode* nxthead = nullptr;

        ListNode* anshead = nullptr;

        while(mover != nullptr)
        {
            counter++;

            // cout << "counter: " << counter << endl;

            if(counter == 1) temphead = mover;

            if(counter == k)
            {
                nxthead = mover->next;
                mover->next = nullptr;

                ListNode* rvhead = nullptr;

                fn(temphead, &rvhead);

                // if(prevhead != nullptr) cout << "prevhead: " << prevhead->val << '\n';
                // else cout << "prev head: NULL" << '\n';

                // if(temphead != nullptr) cout << "temphead: " << temphead->val << '\n';
                // else cout << "temp head: NULL" << '\n';

                // cout << "rv head: " << rvhead->val << endl;

                // if(nxthead != nullptr) cout << "nxthead: " << nxthead->val << '\n';
                // else cout << "nxt head: NULL" << '\n';
 
                if(anshead == nullptr) anshead = rvhead;                

                if(prevhead != nullptr) prevhead->next = rvhead;

                temphead->next = nxthead;

                counter = 0;
                prevhead = temphead;
                mover = nxthead;
            }
            else
            {
                mover = mover->next;
            }
        }

        return anshead;

    }   
};
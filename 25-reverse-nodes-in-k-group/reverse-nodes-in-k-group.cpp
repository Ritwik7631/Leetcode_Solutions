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
    void fn(ListNode* node, ListNode** newHead)
    {
        if (node == nullptr || node->next == nullptr)
        {
            *newHead = node;
            return;
        }

        ListNode* nextNode = node->next;
        fn(nextNode, newHead);
        nextNode->next = node;
        node->next = nullptr;
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
        ListNode* b = nullptr;
        ListNode* a = nullptr;
        ListNode* d = nullptr;

        ListNode* anshead = nullptr;

        while(mover != nullptr)
        {
            counter++;

            cout << "counter: " << counter << endl;

            if(counter == 1) b = mover;

            if(counter == k)
            {
                d = mover->next;
                mover->next = nullptr;

                ListNode* c = nullptr;

                fn(b, &c);

                // if(prevhead != nullptr) cout << "prevhead: " << prevhead->val << '\n';
                // else cout << "prev head: NULL" << '\n';

                // if(temphead != nullptr) cout << "temphead: " << temphead->val << '\n';
                // else cout << "temp head: NULL" << '\n';

                // cout << "rv head: " << rvhead->val << endl;

                // if(nxthead != nullptr) cout << "nxthead: " << nxthead->val << '\n';
                // else cout << "nxt head: NULL" << '\n';
 
                if(anshead == nullptr) anshead = c;                

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

        if(counter > 0 && a != nullptr)
        {
            a->next = b;
        }

        return anshead != nullptr ? anshead : head;
    }   
};
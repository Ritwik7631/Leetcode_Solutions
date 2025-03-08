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
    ListNode* Split(ListNode* x)
    {
        ListNode* prev;
        ListNode* tortoise = x;
        ListNode* rabbit = x;
    
        while(rabbit != nullptr && rabbit->next != nullptr)
        {
            prev = tortoise;
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
        }
    
        return prev;
    }


    ListNode* Merge(ListNode* a)
    {
        if(a == nullptr || a->next == nullptr) return a;

        ListNode* prev_mid = Split(a);
        ListNode* mid = prev_mid->next;
        
        prev_mid->next = nullptr;
        
        ListNode* left = Merge(a);
        ListNode* right = Merge(mid);
        
        ListNode newanshead(0);
        ListNode* tail = &newanshead;
        
        while(left != nullptr && right != nullptr)
        {
            if(left->val < right->val)
            {
                tail->next = left;
            left = left->next;
            }
            else
            {
                tail->next = right;
            right = right->next;
            }
            
            tail = tail->next;
        }
        
        if(right != nullptr) tail->next = right;
        if(left != nullptr) tail->next = left;
        
        return newanshead.next;
    }

    ListNode* sortList(ListNode* head) {
        return Merge(head);
    }
};
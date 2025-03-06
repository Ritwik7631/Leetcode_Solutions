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
    ListNode* half(ListNode* x) {
        ListNode* slow = x;
        ListNode* fast = x;
        ListNode* pre;
        
        while(fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return pre;
    }
    
    ListNode* fn(ListNode* a) {
        if(a == nullptr || a->next == nullptr) return a;
        
        ListNode* pre = half(a);
        ListNode* mid = pre->next;
        pre->next = nullptr;
        
        ListNode* left = fn(a);
        ListNode* right = fn(mid);
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while(left != nullptr && right != nullptr) {
            if(left->val < right->val) {
                tail->next = left;
                left = left->next;
            }
            else {
                tail->next = right;
                right = right->next;
            }
            
            tail = tail->next;
        }
        
        if(left) tail->next = left;
        if(right) tail->next = right;
        
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        return fn(head);
    }
};

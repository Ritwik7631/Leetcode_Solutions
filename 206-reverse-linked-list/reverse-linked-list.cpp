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
    ListNode* ans = nullptr;

    void fn(ListNode* curr, ListNode* prev)
    {   
        if(curr->next == nullptr)
        {
            ans = curr;
            curr->next = prev;
            return;
        }

        fn(curr->next, curr);

        curr->next = prev;
    }

    ListNode* reverseList(ListNode* head) {
        
        ListNode* mover = head;

        if(head == nullptr) return head;

        fn(head, nullptr);

        return ans;
    }
};
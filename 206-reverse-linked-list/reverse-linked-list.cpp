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
    ListNode* ans;

    void fn(ListNode* curr)
    {
        if(curr->next == nullptr)
        {
            ans = curr;
            return;
        }

        fn(curr->next);

        curr->next->next = curr;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        fn(head);

        head->next = nullptr;

        return ans;
    }
};
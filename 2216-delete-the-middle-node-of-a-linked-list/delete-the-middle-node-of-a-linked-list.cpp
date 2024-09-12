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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head->next == nullptr) return nullptr;

        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr && fast->next->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow;

        slow = slow->next->next;

        fast->next = slow;

        return head;

        // fast = head;

        // while(fast->next != slow)
        // {
        //     fast = fast->next;
        // }

        // ListNode* after = slow->next;

        // fast->next = after;

        // return head;
    }
};
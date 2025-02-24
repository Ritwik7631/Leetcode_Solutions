class Solution {
public:
    ListNode* ans = nullptr;

    // Recursive reverse with cycle break.
    void fn(ListNode* curr) {
        if (curr->next == nullptr) {
            ans = curr;
            return;
        }
        fn(curr->next);
        curr->next->next = curr;
        curr->next = nullptr;  // Break the cycle
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Adjusted while loop condition.
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Split the list into two halves.
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        // Reverse the second half.
        fn(second);
        ListNode* rvhead = ans;
        
        // Merge the two halves.
        ListNode* first = head;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (first || rvhead) {
            if (first) {
                tail->next = first;
                tail = tail->next;
                first = first->next;
            }
            if (rvhead) {
                tail->next = rvhead;
                tail = tail->next;
                rvhead = rvhead->next;
            }
        }
    }
};

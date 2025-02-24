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
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && slow->next != nullptr && fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;
        slow->next = nullptr;
        
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

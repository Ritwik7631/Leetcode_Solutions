class Solution {
public:
    // Function to reverse a part of the linked list
    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (k > 0) {
            next = curr->next; // Store next node
            curr->next = prev; // Reverse current node's pointer
            prev = curr;       // Move prev to current node
            curr = next;       // Move curr to next node
            k--;
        }

        return prev; // Return the new head of the reversed list
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;

        // First, check if there are at least k nodes remaining in the list
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }

        // If we have k nodes, we proceed with reversal
        if (count == k) {
            // Reverse the first k nodes
            ListNode* reversedHead = reverseLinkedList(head, k);

            // Now `head` is the last node of the reversed group, connect it to the result of the next recursive call
            head->next = reverseKGroup(curr, k);

            return reversedHead; // Return the new head of the reversed list
        }

        // If there are fewer than k nodes left, don't reverse them
        return head;
    }
};

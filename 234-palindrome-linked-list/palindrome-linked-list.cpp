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
    ListNode* reversehead = nullptr;

    // Function to create a copy of the linked list
    ListNode* copyList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* newHead = new ListNode(head->val);
        ListNode* current = newHead;
        ListNode* original = head->next;

        while (original != nullptr) {
            current->next = new ListNode(original->val);
            current = current->next;
            original = original->next;
        }

        return newHead;
    }

    // Your recursive function to reverse the list
    void fn(ListNode* i, ListNode* j) {
        if (i == nullptr) {
            reversehead = j; // Set the new head of the reversed list
            return;
        }

        fn(i->next, i); // Recursively reverse the rest of the list

        i->next = j; // Reverse the link
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true; // Edge cases: empty or single node list

        // Step 1: Create a copy of the list
        ListNode* copiedList = copyList(head);

        // Step 2: Reverse the copied list
        fn(copiedList, nullptr);

        // Step 3: Compare the original list and the reversed copied list
        ListNode* org = head;
        ListNode* rev = reversehead; // Start from the head of the reversed copied list

        while (org != nullptr && rev != nullptr) {
            if (org->val != rev->val) {
                return false; // Mismatch found, not a palindrome
            }
            org = org->next;
            rev = rev->next;
        }

        // If all nodes matched, the list is a palindrome
        return true;
    }
};

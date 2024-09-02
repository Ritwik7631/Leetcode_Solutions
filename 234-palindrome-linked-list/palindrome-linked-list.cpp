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
    // Function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev; // Return new head of the reversed list
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true; // Edge cases: empty or single node list

        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHalfReversed = reverseList(slow);

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = secondHalfReversed;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                return false; // Mismatch found, not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // If all nodes matched, the list is a palindrome
        return true;
    }
};

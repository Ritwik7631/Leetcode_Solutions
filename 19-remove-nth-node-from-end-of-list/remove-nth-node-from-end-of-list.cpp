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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // First pass: calculate the total length of the list.
        ListNode* mover = head;
        int len = 0;
        while (mover != nullptr) {
            mover = mover->next;
            len++;
        }
        
        if (n == len) {
            return head->next;
        }
        
        int rightbefore = len - n - 1;
        
        int c = 0;
        mover = head;
        while (mover != nullptr) {
            if (c == rightbefore) {
                mover->next = mover->next->next;
                break;
            }
            mover = mover->next;
            c++;
        }
        
        return head;
    }
};

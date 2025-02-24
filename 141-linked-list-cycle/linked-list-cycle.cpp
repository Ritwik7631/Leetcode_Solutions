/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* tortoise = head;

        ListNode* hare = head;

        while(tortoise != nullptr && tortoise->next != nullptr && hare != nullptr)
        {
            tortoise = tortoise->next->next;
            hare = hare->next;

            if(tortoise == hare) return true;
        }

        return false;
    }
};
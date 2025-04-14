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
                // the naive solution would be to count the number of nodes in the list in one pass and then remove the nth node from the end in another pass by total nodes - n
        // the smarter solution is to use two pointers. pointer1 will start from the head and pointer2 will start from the head + n.
        // then we will move both pointers until pointer2 reaches the end of the list.
        // then we will remove the node after pointer1.

        ListNode dummy(0);
        dummy.next = head;

        if(head->next == nullptr) return nullptr;

        ListNode* pointer1 = &dummy;
        ListNode* pointer2 = &dummy;

        for(int i = 0; i <= n; i++)
        {
            pointer2 = pointer2->next;  
        }

        while(pointer2 != nullptr)
        {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }

        pointer1->next = pointer1->next->next;

        return dummy.next;
    }
};
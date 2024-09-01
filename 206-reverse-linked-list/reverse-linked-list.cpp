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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* one = head;
        ListNode* two = head;
        ListNode* three = NULL;

        one = one->next;

        while(two != NULL)
        {
            two->next = three;
            three = two;
            two = one;
            if(one != NULL) one = one->next;
        }

        return three;


        
        
    }
};
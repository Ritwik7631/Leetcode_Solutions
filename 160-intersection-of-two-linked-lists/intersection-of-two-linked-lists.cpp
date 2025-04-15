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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pointer1 = headA;
        ListNode* pointer2 = headB;

        while(true)
        {
            if(pointer1 == pointer2) return pointer1;
            if(pointer1 == nullptr && pointer2 == nullptr) return nullptr;

            if(pointer1 == nullptr) pointer1 = headB;
            else pointer1 = pointer1->next;

            if(pointer2 == nullptr) pointer2 = headA;
            else pointer2 = pointer2->next;

        }

        return nullptr;
    }
};
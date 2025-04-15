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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right)
    {
        ListNode* head = new ListNode(0);

        ListNode* ans = head;

        while(left != nullptr && right != nullptr)
        {
            if(left->val < right->val)
            {
                head->next = left;
                left = left->next;
            }
            else
            {
                head->next = right;
                right = right->next;
            }

            head = head->next;
        }

        while(left != nullptr)
        {
            head->next = left;
            left = left->next;
            head = head->next;
        }

        while(right != nullptr)
        {
            head->next = right;
            right = right->next;
            head = head->next;
        }

        return ans->next;
    }


    ListNode* merge(ListNode* x)
    {
        if(x->next == nullptr) return x;

        ListNode* slow = x;
        ListNode* fast = x;
        ListNode* prev_to_slow = nullptr;

        while(fast != nullptr && fast->next != nullptr)
        {
            prev_to_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* s1 = x;

        ListNode* s2 = slow;

        prev_to_slow->next = nullptr;


        ListNode* left = merge(s1);
        ListNode* right = merge(s2);

        return mergeTwoLists(left, right);

    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;

        if(head->next == nullptr) return head;

        ListNode* dummy = merge(head);

        return dummy;
    }
};
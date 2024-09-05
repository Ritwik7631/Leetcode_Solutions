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
    ListNode* slow = nullptr;

    void fn(ListNode* curr, ListNode* prev)
    {
        // cout << "hi" << endl;

        if(curr == slow)
        {
            curr->next = prev;
            return;
        }

        fn(curr->next, curr);

        curr->next = prev;

        return;
    }

    bool isPalindrome(ListNode* head) {

        slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            if(fast != nullptr) slow = slow->next;
            // cout << slow->val << " " << fast->val << endl;
        }

        ListNode* x = slow->next;
        fn(head, nullptr);        
        
        if(fast != NULL)
        {
            slow = slow->next;
            // cout << fast->val;
        }
        
        // cout << slow->val << " " << fast->val << endl;

        // now slow now becomes new reverse head

        // cout << x->val << endl;

        // cout << x->val << " " << slow->val;

        while(slow != nullptr && x != nullptr)
        {
            // cout << slow->val << " " << x->val << endl;
            if(slow->val != x->val) return false;

            slow = slow->next;
            x = x->next;
        }

        return true;
    }
};
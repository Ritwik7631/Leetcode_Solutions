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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* z = head;
        int count = 0;
        while(z != NULL)
        {
            count++;
            z = z->next;
        }

        if(count <= 2) return head;

        ListNode* org = head;

        ListNode* temp1 = new ListNode(org->val); // even list

        ListNode* temp1head = temp1;

        org = org->next;

        ListNode* temp2 = new ListNode(org->val); // odd list

        ListNode* temp2head = temp2;

        org = org->next;

        ListNode* x = org;

        int i = 2;

        while(x != NULL)
        {
            if(i % 2 == 0)
            {
                ListNode* current = new ListNode(x->val);
                temp1->next = current;
                temp1 = temp1->next;
            }
            else
            {
                ListNode* current = new ListNode(x->val);
                temp2->next = current;
                temp2 = temp2->next;
            }

            x = x->next;
            i++;
        }

        // while(temp1head != NULL)
        // {
        //     cout << temp1head->val << " ";
        //     temp1head = temp1head->next;
        // }

        // while(temp2head != NULL)
        // {
        //     cout << temp2head->val << " ";
        //     temp2head = temp2head->next;
        // }

        ListNode* y = temp1head;

        while(y->next != NULL)
        {
            y = y->next;
        }

        y->next = temp2head;

        return temp1head;

        return org;

    }
};
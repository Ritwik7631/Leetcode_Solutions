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
    ListNode* Merge(ListNode* a, ListNode* b)
    {
        ListNode dummy(0);
        ListNode* ans = &dummy;
        
        ListNode* mover1 = a;
        ListNode* mover2 = b;
        
        // Merge while either list still has nodes.
        while(mover1 != nullptr || mover2 != nullptr)
        {
            // Use INT_MAX for exhausted lists.
            int x = (mover1 != nullptr) ? mover1->val : INT_MAX;
            int y = (mover2 != nullptr) ? mover2->val : INT_MAX;
            
            if(x < y)
            {
                ans->next = mover1;
                mover1 = mover1->next;
            }
            else
            {
                ans->next = mover2;
                mover2 = mover2->next;
            }
            ans = ans->next;
        }
        
        return dummy.next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty()) return nullptr;
        
        // Initialize the answer with the first list.
        ListNode* ans = lists[0];
        
        // Iteratively merge each list into the current answer.
        for(int i = 1; i < lists.size(); i++)
        {
            ans = Merge(ans, lists[i]);
        }
        
        return ans;
    }
};
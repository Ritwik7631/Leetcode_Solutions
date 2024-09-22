/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* mover = head;

        Node* headans = nullptr;

        while(mover != nullptr)
        {
            Node* curr = new Node(mover->val);
            curr->next = mover->next;
            mover->next = curr;

            if(headans == nullptr) headans = curr;

            mover = curr->next;
        }

        // Node* tempmover = head;

        // while(tempmover != nullptr)
        // {
        //     cout << tempmover->val << " ";
        //     tempmover = tempmover->next;
        // }

        // original->next->random = original->random->next

        mover = head;

        while(mover != nullptr)
        {
            if(mover->random != nullptr) mover->next->random = mover->random->next;
            mover = mover->next->next;
        }

        mover = head;
        Node* mover2 = headans;

        while(mover != nullptr)
        {
            if(mover->next != nullptr) mover->next = mover->next->next;

            if(mover2->next != nullptr) mover2->next = mover2->next->next;

            mover = mover->next;

            mover2 = mover2->next;
        }

        return headans;
    }
};
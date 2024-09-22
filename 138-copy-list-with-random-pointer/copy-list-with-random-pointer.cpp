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
        unordered_map<Node*, Node*> mp;

        Node* mover = head;

        Node* mover2 = nullptr;

        Node* headans = nullptr;

        while(mover != nullptr)
        {
            if(mover == head)
            {
                mover2 = new Node(head->val);
                headans = mover2;
            }
            else
            {
                mover2->next = new Node(mover->val);
                mover2 = mover2->next;
            }
            mp[mover] = mover2;
            mover = mover->next;
        }

        mover = head;
        mover2 = headans;

        while(mover != nullptr)
        {
            if(mover->random != nullptr) mover2->random = mp[mover->random];

            mover = mover->next;
            mover2 = mover2->next;
        }

        return headans;

    }
};
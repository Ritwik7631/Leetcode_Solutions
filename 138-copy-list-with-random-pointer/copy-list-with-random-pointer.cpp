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
        unordered_map<Node*, Node*> oldtonew;

        // oldtonew[NULL] = NULL;

        Node* mover = head;

        while(mover != nullptr)
        {
            Node* n = new Node(mover->val);
            n->next = mover->next;
            n->random = mover->random;

            oldtonew[mover] = n;

            mover = mover->next; 
        }

        mover = head;

        while(mover != nullptr)
        {
            Node* copy = oldtonew[mover];
            copy->next = oldtonew[mover->next];
            copy->random = oldtonew[mover->random];
            mover = mover->next;
        }

        return oldtonew[head];
    }
};
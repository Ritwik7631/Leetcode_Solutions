/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;

    void fn(Node* curr)
    {
        if(curr == nullptr)
        {
            return;
        }

        for(auto a : curr->children)
        {
            fn(a);
        }

        ans.push_back(curr->val);
    }

    vector<int> postorder(Node* root) {
        if(root == nullptr) return ans;

        fn(root);

        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;

    void fn(TreeNode* root, int &currmax)
    {
        if(root == nullptr) return;

        if(root->val >= currmax) count++;

        int new_mx = max(currmax, root->val);

        fn(root->left, new_mx);
        fn(root->right, new_mx);
    }

    int goodNodes(TreeNode* root) {
        fn(root, root->val);
        return count;
    }
};
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
    bool fn(TreeNode* root, long MIN, long MAX)
    {   
        if(root == nullptr) return true;

        if(!(root->val > MIN && root->val < MAX)) return false;

        bool l, r;
        l = fn(root->left, MIN, root->val);
        r = fn(root->right, root->val, MAX);

        return l && r;
    }

    bool isValidBST(TreeNode* root) {
        return fn(root, LONG_MIN, LONG_MAX);
    }
};
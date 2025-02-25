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
    TreeNode* anshead = nullptr;

    void fn(TreeNode* a)
    {
        if(a == nullptr) return;
        
        TreeNode* l = a->left;

        TreeNode* r = a->right;

        a->left = r;
        a->right = l;

        fn(a->left);

        fn(a->right);
    }

    TreeNode* invertTree(TreeNode* root) {

        fn(root);

        return root;
    }
};
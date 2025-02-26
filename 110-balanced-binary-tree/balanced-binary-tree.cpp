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
    pair<bool,int> fn(TreeNode* a)
    {
        if(a == nullptr)
        {
            return {true, 1};
        }

        pair<bool,int> leftsubtree = fn(a->left);
        pair<bool,int> rightsubtree = fn(a->right);

        int leftsubtreeH = leftsubtree.second;
        int rightsubtreeH = rightsubtree.second;

        int H = 1 + max(leftsubtreeH, rightsubtreeH);
        bool isbalanced = leftsubtree.first && rightsubtree.first && (abs(rightsubtreeH - leftsubtreeH) <= 1);
        return make_pair(isbalanced, H);
    }
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans = fn(root);

        return ans.first;
    }
};
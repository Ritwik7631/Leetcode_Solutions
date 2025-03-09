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
    int ans = 0;

    int dfs(TreeNode* curr) // dfs() returns the length of the longest path till node: curr
    {
        if(curr == nullptr) return 0;

        int l = dfs(curr->left);
        int r = dfs(curr->right);

        int leftcheck = 0;
        int rightcheck = 0;

        if(curr->left != nullptr && curr->val == curr->left->val)
        {
            leftcheck = l + 1;
        }

        if(curr->right != nullptr && curr->val == curr->right->val)
        {
            rightcheck = r + 1;
        }

        ans = max(ans, leftcheck + rightcheck);

        return max(leftcheck, rightcheck);
    }

    int longestUnivaluePath(TreeNode* root) {
        int x = dfs(root);

        return ans;
    }
};
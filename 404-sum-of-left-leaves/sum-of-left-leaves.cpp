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
    void fn(TreeNode* curr, bool prev_was_left)
    {   
        if(curr == nullptr) return;

        if(curr->left == nullptr && curr->right == nullptr)
        {
            if(prev_was_left)
            {
                ans += curr->val;
            }

            return;
        }

        fn(curr->left, true);
        fn(curr->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        fn(root, false);

        return ans;
    }
};
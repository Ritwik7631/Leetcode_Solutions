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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return root->val;

        queue<TreeNode*> q;

        q.push(root);

        int leftmost;

        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();

            leftmost = curr->val;

            if(curr->right != nullptr)
            {
                q.push(curr->right);
            }

            if(curr->left != nullptr)
            {
                q.push(curr->left);
            }
        }

        return leftmost;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // bfs
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        q.push(make_pair(root, 0));

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int level = front.second;

            if(level == ans.size())
            {
                ans.push_back(vector<int>());
            }

            ans[level].push_back(node->val);

            if(node->left != nullptr)
            {
                q.push(make_pair(node->left, level+1));
            }
            
            if(node->right != nullptr)
            {
                q.push(make_pair(node->right, level+1));
            }
        }

        return ans;
    }
};
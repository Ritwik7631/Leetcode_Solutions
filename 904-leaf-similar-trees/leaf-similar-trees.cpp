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
    void fn(TreeNode* curr, vector<int>& ans)
    {
        if(curr == nullptr) return;

        if(curr->left == nullptr && curr->right == nullptr)
        {
            ans.push_back(curr->val);
            return;
        }

        fn(curr->left, ans);
        fn(curr->right, ans);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1;
        vector<int> r2;

        fn(root1, r1);
        fn(root2, r2);

        for(auto a : r1) cout << a << " " << endl;
        for(auto b : r2) cout << b << " " << endl;

        return r1 == r2;
    }
};
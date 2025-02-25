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

    void fn(TreeNode* a, int &curr)
    {
        if(a == nullptr) return;

        curr++;
        ans = max(ans, curr);
        fn(a->left, curr);
        curr--;
        curr++;
        ans = max(ans, curr);
        fn(a->right, curr);
        curr--;
    }

    int maxDepth(TreeNode* root) {

        int curr = 0;
        fn(root, curr);

        return ans;
    }
};
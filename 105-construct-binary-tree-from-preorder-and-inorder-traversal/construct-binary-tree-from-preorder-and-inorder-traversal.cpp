/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution {
public:
    TreeNode* fn(int preStart, int preEnd, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){

        if(preStart > preEnd || inStart > inEnd) return nullptr;
      
        TreeNode* root = new TreeNode(preorder[preStart]);

        int x;
        for(int j = inStart; j <= inEnd; j++){
          if(inorder[j] == preorder[preStart])
            {
                x = j;
                break;
            }
        }

        int to_the_left = x - inStart;
        int to_the_right = inEnd - x - 1;

        root->left = fn(preStart + 1, preStart + to_the_left, inStart, x-1, preorder, inorder);
        root->right = fn(preStart + to_the_left + 1, preEnd, x+1, inEnd, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder[0] will be the head

        return fn(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);  
    }
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "N,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    TreeNode* deserialize(string data) {
    vector<string> tokens;
    string token;
    for (char c : data) {
        if (c != ',') {
            token.push_back(c);
        } else {
            tokens.push_back(token);
            token.clear();
        }
    }
    // In case there's any token left.
    if (!token.empty())
        tokens.push_back(token);

    int index = 0;
    return buildTree(tokens, index);
    }
    
    TreeNode* buildTree(const vector<string>& tokens, int &index) {
        if (index >= tokens.size() || tokens[index] == "N") {
            index++; // Move past the "N"
            return nullptr;
        }
        
        // Convert the current token to an integer.
        int value = stoi(tokens[index]);
        index++; // Move to the next token
        TreeNode* node = new TreeNode(value);
        
        node->left = buildTree(tokens, index);
        node->right = buildTree(tokens, index);
        
        return node;
    }
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};

        for (char c : s) {
            if (mapping.count(c)) {  // If it's a closing bracket
                if (stk.empty() || stk.top() != mapping[c]) {
                    return false;
                }
                stk.pop();  // Pop the matching opening bracket
            } else {
                stk.push(c);  // Push opening brackets
            }
        }

        return stk.empty();  // Valid if stack is empty
    }
};

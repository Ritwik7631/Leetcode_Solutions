class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(auto a : s) 
        {
            if(a == '(' || a == '{' || a == '[') 
            {
                stk.push(a);
            }
            else 
            {
                if(stk.empty()) return false;

                char top = stk.top();
                if((a == ')' && top == '(') || 
                (a == '}' && top == '{') || 
                (a == ']' && top == '[')) 
                {
                    stk.pop();
                }
                else 
                {
                    return false;
                }
            }
        }

        return stk.empty();

    }
};
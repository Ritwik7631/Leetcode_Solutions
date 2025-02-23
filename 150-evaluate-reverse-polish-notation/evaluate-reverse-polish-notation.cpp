class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(auto a : tokens)
        {
            if(a == "*" || a == "/" || a == "+" || a == "-")
            {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                if(a == "*") stk.push(x*y);
                else if(a == "/") stk.push(y/x);
                else if(a == "+") stk.push(x+y);
                else stk.push(y-x);
            }
            else
            {
                stk.push(stoi(a));
            }
        }

        return stk.top();
    }
};
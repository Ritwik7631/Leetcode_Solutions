class Solution {
public:
    vector<string> ans;
    bool valid(string &temp)
    {
        stack<char> stk;

        for(auto a : temp)
        {
            if(a == '(') stk.push('(');
            else
            {
                if(stk.empty()) return false;
                stk.pop();
            }
        }

        return stk.empty();
    }

    void fn(int o, int c, string temp)
    {
        if(o <= 0 && c <= 0)
        {
            if(valid(temp)) ans.push_back(temp);

            return;
        }

        if(o - 1 >= 0)
        {
            fn(o-1, c, temp + "(");
        }

        if(c - 1 >= 0)
        {
            fn(o, c-1, temp + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();
        fn(n,n, "");

        return ans;
    }
};
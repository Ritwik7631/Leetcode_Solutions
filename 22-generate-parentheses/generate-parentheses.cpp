class Solution {
public:
    void fn(int o, int c, string temp, vector<string> &ans)
    {
        if(o <= 0 && c <= 0)
        {
            ans.push_back(temp);

            return;
        }

        if(o - 1 >= 0)
        {
            fn(o-1, c, temp + "(", ans);
        }

        if(c > o)
        {
            fn(o, c-1, temp + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        fn(n,n, "", ans);

        return ans;
    }
};
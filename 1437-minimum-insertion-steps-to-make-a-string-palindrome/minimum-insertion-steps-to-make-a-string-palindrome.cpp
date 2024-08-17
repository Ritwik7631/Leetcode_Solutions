class Solution {
public:
    int fn(int l, int r, string &s, vector<vector<int>> &dp)
    {
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == s[r])
        {
            return dp[l][r] = fn(l+1, r-1, s, dp);
        }
        
        return dp[l][r] = 1 + min(fn(l, r-1, s, dp), fn(l+1, r, s, dp));
    }

    int minInsertions(string s) {
        int l = 0;
        int r = s.size() - 1;

        vector<vector<int>> dp(s.size() + 1, vector<int> (s.size()+1, -1));

        return fn(l, r, s, dp);
    }
};
class Solution {
public:
    int fn(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i > j)
        {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j])
        {
            return dp[i][j] = fn(i+1, j-1, s,dp);
        }

        return dp[i][j] = 1 + min(fn(i, j-1, s,dp), fn(i+1, j, s,dp));
    }

    int minInsertions(string s) {
        int n = s.size()-1;
        int l = 0;
        int r = n;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return fn(l,r,s,dp);
    }
};
class Solution {
public:
    int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if(i >= a.size() || j >= b.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j])
        {
            return dp[i][j] = 1 + fn(i+1, j+1, a, b,dp);
        }

        return dp[i][j] = max(fn(i+1, j,a,b,dp), fn(i, j+1,a,b,dp));
    }

    int longestCommonSubsequence(string a, string b) {
        int i = 0;
        int j = 0;

        vector<vector<int>> dp(a.size()+1, vector<int> (b.size() + 1, -1));

        return fn(i,j,a,b,dp);
    }
};
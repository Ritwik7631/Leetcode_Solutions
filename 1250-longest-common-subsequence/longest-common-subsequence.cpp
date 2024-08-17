class Solution {
public:
    // int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    // {
    //     if(i >= a.size() || j >= b.size()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(a[i] == b[j])
    //     {
    //         return dp[i][j] = 1 + fn(i+1, j+1, a, b,dp);
    //     }

    //     return dp[i][j] = max(fn(i+1, j,a,b,dp), fn(i, j+1,a,b,dp));
    // }

    int longestCommonSubsequence(string a, string b) {
        int i = 0;
        int j = 0;

        vector<vector<int>> dp(a.size()+1, vector<int> (b.size() + 1, 0));

        for(int i = a.size()-1; i >= 0; i--)
        {
            for(int j = b.size()-1; j >= 0; j--)
            {
                if(a[i] == b[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);               
            }
        }

        return dp[0][0];
    }
};
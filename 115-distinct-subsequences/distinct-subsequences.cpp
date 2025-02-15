#define mod 1000000007
class Solution {
public:
    // int fn(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    // {
    //     if(j < 0) return 1;

    //     if(i < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == t[j])
    //     {
    //         return dp[i][j] = fn(i-1, j-1, s, t, dp) + fn(i-1, j, s, t, dp); 
    //     }

    //     return dp[i][j] = fn(i-1, j, s, t, dp);
    // }

    int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n, vector<int> (m, -1));
    //     return fn(n-1, m-1, s, t, dp);

// -----------------------------------------------------------------------------------------------
// bottom up

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1] % mod + dp[i-1][j] % mod)%mod; 
                }
                else dp[i][j] = dp[i-1][j]%mod;             
            }
        }

        return dp[n][m];
    }
};
class Solution {
public:
    int fn(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(j < 0) return 1;

        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j])
        {
            return dp[i][j] = fn(i-1, j-1, s, t, dp) + fn(i-1, j, s, t, dp); 
        }

        return dp[i][j] = fn(i-1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return fn(n-1, m-1, s, t, dp);

// -----------------------------------------------------------------------------------------------
// bottom up

        // int n = s.size();
        // int m = t.size();

        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // for(int i = 0; i <= n; i++)
        // {
        //     dp[i][0] = 1;
        // }

        // for(int i = 1; i <= n; i++)
        // {
        //     for(int j = 1; j <= m; j++)
        //     {
        //         int count = 0;
        //         if(s[i] == t[j])
        //         {
        //             count = dp[i-1][j-1]; 
        //         }
        //         else
        //         {
        //             dp[i][j] = count + dp[i-1][j];
        //         }                
        //     }
        // }

        // return dp[n-1][m-1];
    }
};
class Solution {
public:
    // bool fn(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    // {
    //     if(j == p.size())
    //     {
    //         return i == s.size();
    //     }

    //     if(i == s.size())
    //     {
    //         return p[j] == '*' && fn(i, j+1, s, p, dp);
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == p[j] || p[j] == '?')
    //     {
    //         return dp[i][j] = fn(i+1, j+1, s, p, dp);
    //     }
    //     else if(p[j] == '*') return dp[i][j] = fn(i, j+1, s, p, dp) || fn(i+1, j, s, p, dp);
    //     else return dp[i][j] = false;
    
    // }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: Empty pattern matches with empty string
        dp[n][m] = 1;

        // Fill the DP table
        for (int i = n; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool match = (i < n && (s[i] == p[j] || p[j] == '?'));
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j + 1] || (i < n && dp[i + 1][j]);
                } else if (match) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0];
    }
};
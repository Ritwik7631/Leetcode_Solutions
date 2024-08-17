class Solution {
public:
    // int fn(int l, int r, string &s, vector<vector<int>> &dp)
    // {
    //     if(l >= r) return 0;

    //     if(dp[l][r] != -1) return dp[l][r];

    //     if(s[l] == s[r])
    //     {
    //         return dp[l][r] = fn(l+1, r-1, s, dp);
    //     }
        
    //     return dp[l][r] = 1 + min(fn(l, r-1, s, dp), fn(l+1, r, s, dp));
    // }

    int minInsertions(string s) {
        // int l = 0;
        // int r = s.size() - 1;

        // int n = s.size();

        // vector<vector<int>> dp(s.size()+1, vector<int> (s.size()+1, 0));

        // for(int l = n-1; l >= 0; l--)
        // {
        //     for(int r = 0; r < n; r++)
        //     {
        //         if(l >= r) continue;

        //         if(s[l] == s[r])
        //         {
        //             dp[l][r] = dp[l+1][r-1];
        //             continue;
        //         }
                
        //         dp[l][r] = 1 + min(dp[l][r-1], dp[l+1][r]);
        //     }
        // }

        // return dp[0][n-1];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        int n = s.size();

        vector<int> current(n, 0);
        vector<int> next(n, 0);

        for(int l = n-1; l >= 0; l--)
        {
            for(int r = 0; r < n; r++)
            {
                if(l >= r) continue;

                if(s[l] == s[r])
                {
                    current[r] = next[r-1];
                    continue;
                }
                
                current[r] = 1 + min(current[r-1], next[r]);
            }

            next = current;
        }

        return next[n-1];

    }
};
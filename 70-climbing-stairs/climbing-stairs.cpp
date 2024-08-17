class Solution {
public:
    // int fn(int i, vector<int> &dp)
    // {
    //     if(i == 0 || i == 1) return 1;

    //     if(dp[i] != -1) return dp[i];

    //     return dp[i] = fn(i-1, dp) + fn(i-2, dp);
    // }

    int climbStairs(int n) {
        
        // vector<int> dp(n+1, -1);
        // return fn(n, dp);
// -------------------------------------------------------------------------------------
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];



        // int a = 1;
        // int b = 1;

        // int cur;

        // for(int i = 2; i <= n; i++)
        // {
        //     cur = a + b;

        //     a = b;
        //     b = cur;
            
        // }
        
        // return b;
    }
};
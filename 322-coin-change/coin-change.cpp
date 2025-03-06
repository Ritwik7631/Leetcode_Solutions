class Solution {
public:
    int fn(int i, int a, vector<int>& coins, vector<vector<int>> &dp)
    {   
        if(a == 0) return 0;

        if(i < 0) return INT_MAX;

        if(dp[i][a] != -1) return dp[i][a];

        int notpick = fn(i-1, a, coins, dp);

        int pick = INT_MAX;

        if(a - coins[i] >= 0)
        {
            int res = fn(i, a - coins[i], coins, dp);

            if(res < INT_MAX) pick = res + 1;
        }

        return dp[i][a] = min(pick, notpick);
        
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+2, -1));

        int ans = fn(n-1, amount, coins, dp);

        if(ans == INT_MAX) return -1;

        return ans;

// ----------------------------------------------------------------
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount+2, amount+1));

        // for(int i = 0; i < n; i++)
        // {
        //     dp[i][0] = 0;
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     for(int a = 1; a <= amount; a++)
        //     {
        //         int notpick = amount + 1;

        //         if(i-1 >= 0) notpick = dp[i-1][a];

        //         int pick = amount + 1;

        //         int val = a - coins[i];

        //         if(val >= 0)
        //         {
        //             pick =  dp[i][val]%mod + 1;
        //         }

        //         dp[i][a] = min(pick, notpick);                
        //     }
        // }

        // if(dp[n-1][amount] >= amount + 1) return -1;

        // return dp[n-1][amount];

// -----------------------------------------------------------------------------


    }
};


/*

[5 2 2] sm = 12

fn(2, 12)
   -> notpick fn(1,12)
              -> notpick fn(0, 12) = 0
                         -> return 12/5 = 2.2 = not even so we return 0
              -> pick fn(1, 10) + 1
                      -> notpick fn(0, 10) = 5
                                 -> return 10/2 = 5
                      -> pick fn(1, 8) + 1
                              -> notpick fn(0, 8) = 4
                                         -> return 8/2 = 4
                              -> pick fn(1, 6) + 1
                                      -> notpick fn(0,6) = 3
                                                 -> return 6/2 = 3
                                      -> pick fn(1,4) + 1
                                              -> notpick fn(0, 4) = 2
                                                         -> return 4/2 = 2
                                              -> pick fn(1, 2) + 1
   -> pick fn(2, 10) + 1



*/
class Solution {
public:
    int fn(int i, int a, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(a <= 0)
        {
            return 0;
        }

        if(i <= 0)
        {
            if(a % coins[0] == 0)
            {
                return a/coins[0];
            }
            else
            {
                return 1000000;
            }
        }

        if(dp[i][a] != -1) return dp[i][a];

        int notpick = fn(i-1, a, coins, dp);

        int pick = 1000000;

        if(a - coins[i] >= 0)
        {
            pick =  fn(i, a - coins[i], coins, dp) + 1;
        }

        return dp[i][a] = min(pick, notpick);
        
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+2, -1));

        int ans = fn(n-1, amount, coins, dp);

        if(ans == 1000000) return -1;

        return ans;
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
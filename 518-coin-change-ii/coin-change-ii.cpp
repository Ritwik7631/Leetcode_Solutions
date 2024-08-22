int fn(int i, int j, vector<int>& coins, vector<vector<int>> &dp)
{   
    if(i < 0)
    {
        if(j == 0) return 1;
        
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];
    
    int pick = 0;
    if(coins[i] <= j)
    {
        pick = fn(i, j - coins[i], coins, dp);
    }

    int notpick = fn(i-1, j, coins, dp);

    return dp[i][j] = pick + notpick;
}

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return fn(coins.size()-1, amount, coins, dp);
    }
};
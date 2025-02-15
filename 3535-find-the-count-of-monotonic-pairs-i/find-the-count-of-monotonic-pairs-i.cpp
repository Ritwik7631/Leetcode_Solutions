class Solution {
public:
    int mod = 1e9+7;

    int fn(int i, int LIE, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i == nums.size()) return 1;

        int ans = 0;
        int x = nums[i];
        int lb;

        if(dp[i][LIE] != -1) return dp[i][LIE];

        if(i == 0)
        {
            lb = 0;
        }
        else
        {
            lb = LIE;

            int tmp = x - nums[i-1] + LIE;

            if(tmp > lb)
            {
                lb = tmp;
            }
        }

        for(int j = lb; j <= x; j++)
        {
            ans = (ans + fn(i+1, j, nums, dp) % mod) % mod;
        }

        return dp[i][LIE] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (51, -1));
        return fn(0,0,nums, dp);
    }
};
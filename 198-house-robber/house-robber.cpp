class Solution {
public:
    int fn(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        int notpick = fn(i-1,nums,dp);

        int pick = nums[i] + fn(i-2, nums,dp);

        return dp[i] = max(notpick, pick); 
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return fn(n-1, nums,dp);
    }
};
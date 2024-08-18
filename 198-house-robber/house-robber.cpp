class Solution {
public:
    int fn(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i < 0) return 0;
        if(i == 0)
        {
            return nums[i];
        }

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + fn(i-2, nums, dp);
        int notpick = fn(i-1, nums, dp);

        return dp[i] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n+1, -1);

        return fn(n-1, nums, dp);

        // int n = nums.size();
        // if (n == 0) return 0;
        // if (n == 1) return nums[0];

        // vector<int> dp(n+1, 0);

        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // int a = nums[0];
        // int b = max(nums[0], nums[1]);
        // int cur;

        // for(int i = 2; i < n; i++)
        // {
        //     int pick = nums[i] + a;
        //     int notpick = b;

        //     cur = max(pick, notpick);

        //     a = b;
        //     b = cur;
            

        // }

        // return b;
    }
};
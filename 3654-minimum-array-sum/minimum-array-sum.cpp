class Solution {
public:
    int x;
    int fn(int i, int rem1, int rem2, vector<int>& nums, vector<vector<vector<int>>> &dp)
    {
        if(i == nums.size()) return 0;

        if(dp[i][rem1][rem2] != -1) return dp[i][rem1][rem2];

        int ans;
        int o1 = (nums[i]+1)/2;
        int o2 = (nums[i]-x);
        // do nothing
        int c1 = nums[i] + fn(i+1, rem1, rem2, nums, dp);

        // do op1 only
        int c2 = INT_MAX;
        if(rem1 > 0) c2 = o1 + fn(i+1, rem1-1, rem2, nums, dp);

        // do op2 only
        int c3 = INT_MAX;
        if(nums[i] >= x && rem2 > 0) c3 = o2 + fn(i+1, rem1, rem2-1, nums, dp);

        // op1 then op2
        int c4 = INT_MAX;
        if(o1 >= x && rem1 > 0 && rem2 > 0) c4 = (o1-x) + fn(i+1, rem1-1, rem2-1, nums, dp);

        // op2 then op1
        int c5 = INT_MAX;
        if(nums[i] >= x  && rem1 > 0 && rem2 > 0) c5 = (o2+1)/2 + fn(i+1, rem1-1, rem2-1, nums, dp);

        return dp[i][rem1][rem2] = min({c1,c2,c3,c4,c5});
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        x = k;
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>> (op1 + 1, vector<int> (op2 + 1, -1)));
        return fn(0, op1, op2, nums, dp);
    }
};
class Solution {
public:
    int fn(int i, vector<int>& nums, vector<int>& dp)
    {
        if(i < 0) return 0;

        if(dp[i] != -1) return dp[i];

        // rob
        int rob = nums[i] + fn(i-2, nums,dp);

        // no rob
        int norob = fn(i-1, nums,dp);

        return dp[i]=max(rob, norob);
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> a(nums.begin()+1, nums.end());
        vector<int> b(nums.begin(), nums.begin()+n-1);

        vector<int> dp1(a.size()+1, -1);
        vector<int> dp2(b.size()+1, -1);

        return max(fn(a.size()-1, a, dp1), fn(b.size()-1, b, dp2));
    }
};
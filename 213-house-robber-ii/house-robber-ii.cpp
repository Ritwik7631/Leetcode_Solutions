class Solution {
public:
    int fn(int i, vector<int>& nums, vector<int>& dp)
    {   
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i];
        if (i >= 2) {
            pick += fn(i-2, nums, dp);
        }
        int notpick = fn(i-1, nums, dp);

        return dp[i] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        int a = nums1.size();
        int b = nums2.size();

        vector<int> dp(a, -1);
        vector<int> dp2(b, -1);

        return max(fn(a-1, nums1, dp), fn(b-1, nums2, dp2));

// --------------------------------------------------------------

        // int n = nums.size();
        // if(n == 1) return nums[0];

        // vector<int> nums1(nums.begin(), nums.end()-1);
        // vector<int> nums2(nums.begin()+1, nums.end());

        // int a = nums1.size();
        // int b = nums2.size();

        // vector<int> dp(a, 0);
        // vector<int> dp2(b, 0);

    }
};

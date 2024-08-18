class Solution {
public:
    // int fn(int i, vector<int>& nums, vector<int>& dp)
    // {   
    //     if(i < 0) return 0;
    //     if(dp[i] != -1) return dp[i];

    //     int pick = nums[i];
    //     if (i >= 2) {
    //         pick += fn(i-2, nums, dp);
    //     }
    //     int notpick = fn(i-1, nums, dp);

    //     return dp[i] = max(pick, notpick);
    // }

    int bottomup(vector<int> nums)
    {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            int pick = nums[i] + dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);            
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {

        // int n = nums.size();
        // if (n == 1) return nums[0];

        // vector<int> nums1(nums.begin(), nums.end()-1);
        // vector<int> nums2(nums.begin() + 1, nums.end());

        // int a = nums1.size();
        // int b = nums2.size();

        // vector<int> dp(a, -1);
        // vector<int> dp2(b, -1);

        // return max(fn(a-1, nums1, dp), fn(b-1, nums2, dp2));

// --------------------------------------------------------------

        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> arr1(nums.begin() + 1, nums.end()); 
        vector<int> arr2(nums.begin(), nums.end() - 1); 

        int ans1 = bottomup(arr1);
        int ans2 = bottomup(arr2);

        return max(ans1, ans2);       
    }
};

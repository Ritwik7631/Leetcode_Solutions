class Solution {
public:
    // we calculate the remaining_sum to intially be sum of entire input
    // fn determines if we can achieve two subsets that are equal from 0 to i
    // bool fn(int i, int sm, vector<int>& nums, vector<vector<int>> &dp)
    // {   
    //     if(sm == 0) return true;

    //     if(i < 0) return false;

    //     if(dp[i][sm] != -1) return dp[i][sm];

    //     bool pick = false;

    //     if(sm - nums[i] >= 0)
    //     {
    //         pick = fn(i-1, sm - nums[i], nums,dp);
    //     }
    
    //     bool notpick = fn(i-1, sm, nums,dp);

    //     return dp[i][sm] = pick || notpick;
    // }

    bool canPartition(vector<int>& nums) {
        // int sm = 0;
        // for(auto it : nums) sm += it;
        
        // if(sm % 2 == 1) return false;

        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (sm/2 + 1, -1));

        // return fn(n-1, sm/2, nums,dp);

        // Bottom Up --------------------------------------------

        // int sm = 0;

        // for(auto it : nums) sm += it;

        // if(sm % 2 == 1) return false;
        
        // int n = nums.size();

        // vector<vector<int>> dp(n, vector<int> (sm/2 + 1, 0));

        // for(int i = 0; i < n; i++) dp[i][0] = true;

        // for(int j = 0; j <= sm/2; j++)
        // {
        //     if(j - nums[0] == sm/2)
        //     {
        //         dp[0][j] = true;
        //     }
        // }

        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 1; j <= sm/2; j++)
        //     {
        //         bool pick = false;

        //         if(j - nums[i] >= 0)
        //         {
        //             pick = dp[i-1][j-nums[i]];
        //         }
            
        //         bool notpick = dp[i-1][j];

        //         dp[i][j] = pick || notpick;
        //     }
        // }

        // return dp[n-1][sm/2];

        // Space Optimized --------------------------------

        int sm = 0;

        for(auto it : nums) sm += it;

        if(sm % 2 == 1) return false;
        
        int n = nums.size();

        vector<int> prev(sm/2 + 1, 0);
        prev[0] = true;

        for(int j = 1; j <= sm/2; j++)
        {
            if(j - nums[0] == sm/2)
            {
                prev[j] = true;
            }
        }

        vector<int> cur(sm/2 + 1, 0);

        for(int i = 1; i < n; i++)
        {
            cur[0] = true;
            for(int j = 1; j <= sm/2; j++)
            {
                bool pick = false;

                if(j - nums[i] >= 0)
                {
                    pick = prev[j-nums[i]];
                }
            
                bool notpick = prev[j];

                cur[j] = pick || notpick;
            }
            prev = cur;
        }

        return prev[sm/2];

        
    }
};
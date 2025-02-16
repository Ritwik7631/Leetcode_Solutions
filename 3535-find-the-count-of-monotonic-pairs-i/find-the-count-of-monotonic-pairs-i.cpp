class Solution {
public:
    int mod = 1e9+7;

    int fn(int i, int LIE, vector<int> &nums, vector<vector<int>> &dp) // fn() returns the total count of monotonic pairs i to n-1 given an LIE.
    {
        if(i == nums.size())
        {
            return 1;
        }

        if(dp[i][LIE] != -1) return dp[i][LIE];

        int x = nums[i];

        int lb;

        if(i == 0)
        {
            lb = 0;
        }
        else
        {
            lb = LIE;

            int tmp = x + LIE - nums[i-1];

            if(tmp > lb)
            {
                lb = tmp;
            }
        }

        int ans = 0;

        for(int k = lb; k <= x; k++)
        {
            ans = (ans + fn(i+1,k,nums,dp)) % mod;
        }

        return dp[i][LIE] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        // dec[i] = input[i] - inc[i]

        // dec[i-1] >= dec[i]
        // input[i-1] - inc[i-1] >= input[i] - inc[i]
        // input[i-1] - inc[i-1] - input[i] >= -inc[i]
        // -input[i-1] + inc[i-1]/LIE + input[i] <= inc[i] - decreasing

        // inc[i] >= inc[i-1]/LIE - increasing
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (51, -1));
        return fn(0, 0, nums, dp); 
    }

    /*
    [2,3,2]

    2,2,2           0,1,0
    2,2,1           
    2,2,0

    2,1,1
    2,1,0

    2,0,0

    1,1,1
    1,1,0
    
    1,0,0

    0,0,0

    [2,3,2]
    LIE = 0
    inc[0,1] input = 3 x = 0,1,2,3 inc[i] >= 3 + 0 - 2 -> inc[i] >= 1
    dec[2,2]


    */
};
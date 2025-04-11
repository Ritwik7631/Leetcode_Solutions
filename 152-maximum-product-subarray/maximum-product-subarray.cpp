class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0];

        int mx_ending_here = nums[0];
        int min_ending_here = nums[0];

        int n = nums.size();

        for(int i = 1; i < n; i++)
        {
            int temp = mx_ending_here;

            mx_ending_here = max({nums[i], nums[i] * mx_ending_here, nums[i] * min_ending_here});

            min_ending_here = min({nums[i], nums[i] * temp, nums[i] * min_ending_here});

            mx = max(mx, mx_ending_here);
        }

        return mx;
    }
};
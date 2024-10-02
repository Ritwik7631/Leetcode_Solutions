class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        // time complexity will not allow nested for loops

        // for(auto a : prefix)
        // {
        //     cout << "  " << a << "  ";
        // }
        // cout << endl;

        // for(auto a : suffix)
        // {
        //     cout << "  " << a << "  ";
        // }
        // cout << endl;

        int max_subarray_sum = INT_MIN;
        int current_prefix_sum = 0;
        int min_prefix_sum = 0;

        for(int i = 0; i < n; i++)
        {
            current_prefix_sum += nums[i];

            max_subarray_sum = max(max_subarray_sum, current_prefix_sum - min_prefix_sum);

            min_prefix_sum = min(min_prefix_sum, current_prefix_sum);
        }

        return max_subarray_sum;
    }
};
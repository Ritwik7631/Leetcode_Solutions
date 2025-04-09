class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;

        int current_sum = 0;

        for(auto a : nums)
        {
            current_sum += a;

            max_sum = max(max_sum, current_sum);

            if(current_sum < 0)
            {
                current_sum = 0;
            }
        }


        return max_sum;
    }
};
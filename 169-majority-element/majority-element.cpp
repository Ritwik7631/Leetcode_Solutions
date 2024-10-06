class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int limit = n/2;

        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1]) count++;
            else count = 1;

            if(count > limit) return nums[i];
        }

        return INT_MIN;
    }
};
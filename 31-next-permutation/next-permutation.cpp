class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n-1;

        while(i > 0 && nums[i] <= nums[i-1])
        {
            i--;
        }

        if(i == 0)
        {
            reverse(nums.begin(), nums.end()); 
            return;
        }

        // sort(nums.begin() + i, nums.end()); // THIS IS NOT ALLOWED

        reverse(nums.begin() + i, nums.end());

        for(int k = i; k < n; k++)
        {
            if(nums[k] > nums[i-1])
            {
                nums[i-1] = nums[i-1]^nums[k];
                nums[k] = nums[k]^nums[i-1];
                nums[i-1] = nums[i-1]^nums[k];
                break;
            }
        }

        return;




    }
};
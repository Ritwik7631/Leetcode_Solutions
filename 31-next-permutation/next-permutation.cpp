class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int valley_ind = -1;

        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                valley_ind = i;
                break;
            }
        }

        if(valley_ind == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int x;

        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] > nums[valley_ind])
            {
                x = i;
                break;
            }
        }

        swap(nums[x], nums[valley_ind]);

        reverse(nums.begin() + valley_ind + 1, nums.end());
    }
};
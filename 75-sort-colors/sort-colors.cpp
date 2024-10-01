class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) return;

        int l = 0, m = 0;

        int r = nums.size() - 1;

        while(m <= r)
        {
            if(nums[m] == 2)
            {
                // swap nums[m] and nums[r]
                // decrement r
                swap(nums[m], nums[r]);
                r--;
            }
            else if(nums[m] == 0)
            {
                // swap nums[l] and nums[m]
                // increment l
                // increment m
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else
            {
                // increment m
                m++;
            }
        }

        return;
        
    }
};
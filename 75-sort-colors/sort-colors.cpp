class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, m = 0;
        int n = nums.size();
        int r = n-1;

        while(m <= r)
        {
            if(nums[m] == 2)
            {
                swap(nums[m], nums[r]);
                r--;
            }
            else if(nums[m] == 0)
            {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else
            {
                m++;
            }
        }

        return;
    }
};
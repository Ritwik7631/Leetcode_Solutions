class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        if(nums[l] == target) return l;

        return -1;
    }
};
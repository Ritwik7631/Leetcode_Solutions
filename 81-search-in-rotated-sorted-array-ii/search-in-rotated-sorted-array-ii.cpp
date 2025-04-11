class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) return true;

            if(nums[l] == nums[mid])
            {
                l++;
                continue;
            }

            if(nums[l] <= nums[mid])
            {
                if(target >= nums[l] && target <= nums[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(target > nums[mid] && target <= nums[r])
                {
                    l = mid+1;
                }
                else
                {
                    r = mid;
                }
            }
        }

        return (nums[l] == target) ? true : false;
    }
};
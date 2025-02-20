class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            int complement = target - nums[i];

            int lo = 0;
            int hi = n-1;

            while(lo < hi)
            {
                int mid = (lo + hi)/2;

                if(mid == i) break;

                if(nums[mid] < complement)
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid;
                }
            }

            if(nums[lo] == complement && lo != i)
            {
                int mn = min(lo,i) + 1;
                int mx = max(lo,i) + 1;

                return {mn, mx};
            }
        }

        return {0,0};
    }
};
class Solution {
public:
    int divide(int l, int r, vector<int>& nums)
    {
        if(l == r) return nums[l];

        int mid = l + (r-l)/2;

        int left = divide(l, mid, nums);
        int right = divide(mid+1, r, nums);
        int combined = fn(nums, l, r, mid);

        return max({left, right, combined});
    }

    int fn(vector<int>& nums, int l, int r, int mid)
    {
        int max_left = INT_MIN;
        int curr = 0;
        for(int i = mid; i >= l; i--)
        {
            curr += nums[i];
            max_left = max(max_left, curr);
        }

        int max_right = INT_MIN;
        curr = 0;
        for(int i = mid+1; i <= r; i++)
        {
            curr += nums[i];
            max_right = max(max_right, curr);
        }

        return max_right + max_left;
    }

    int maxSubArray(vector<int>& nums) {
        return divide(0, nums.size()-1, nums);
    }
};
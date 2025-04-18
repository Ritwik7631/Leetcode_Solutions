class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;

        int n = nums.size();

        for(int i = 0; i < n; i = i + 2)
        {
            ans += min(nums[i], nums[i+1]);
        }

        return ans;
    }

    // 1 2 2 5 6 6
    // 1 + 2 + 6 = 9
};
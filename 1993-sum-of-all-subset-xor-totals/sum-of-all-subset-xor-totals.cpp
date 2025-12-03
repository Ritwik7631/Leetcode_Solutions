class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int mask = 0; mask < (1 << n); mask++) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) x ^= nums[i];
            }
            total += x;
        }

        return total;
    }
};

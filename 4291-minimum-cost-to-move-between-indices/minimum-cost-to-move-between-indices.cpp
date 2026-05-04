class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Required by the prompt
        vector<int> lomviretas = nums;

        vector<int> closest(n);
        closest[0] = 1;
        closest[n - 1] = n - 2;

        for (int i = 1; i < n - 1; i++) {
            int leftGap = nums[i] - nums[i - 1];
            int rightGap = nums[i + 1] - nums[i];

            if (leftGap <= rightGap) {
                closest[i] = i - 1;
            } else {
                closest[i] = i + 1;
            }
        }

        vector<long long> prefRight(n, 0);
        vector<long long> prefLeft(n, 0);

        for (int i = 0; i < n - 1; i++) {
            long long cost = (closest[i] == i + 1) ? 1LL : nums[i + 1] - nums[i];
            prefRight[i + 1] = prefRight[i] + cost;
        }

        for (int i = 1; i < n; i++) {
            long long cost = (closest[i] == i - 1) ? 1LL : nums[i] - nums[i - 1];
            prefLeft[i] = prefLeft[i - 1] + cost;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            if (l < r) {
                ans.push_back((int)(prefRight[r] - prefRight[l]));
            } else {
                ans.push_back((int)(prefLeft[l] - prefLeft[r]));
            }
        }

        return ans;
    }
};

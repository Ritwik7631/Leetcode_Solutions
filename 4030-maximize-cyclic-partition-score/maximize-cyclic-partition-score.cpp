#include <bits/stdc++.h>
using namespace std;

class Solution {
    // 3573 helper: Best Time to Buy and Sell Stock V on a *segment* [l, r) over cyclic prices
    // prices is treated as cyclic via i % n
    // We run a bottom-up DP in O((r-l) * k)
    long long maximumProfitSegment(vector<int>& prices, int l, int r, int k) {
        int n = (int)prices.size();

        // f[j][0] = flat
        // f[j][1] = holding long
        // f[j][2] = holding short
        // j runs 1..k+1, where "transaction count" is encoded so that final answer is f[k+1][0]
        const long long NEG = LLONG_MIN / 4;
        vector<array<long long,3>> f(k + 2, {NEG, NEG, NEG});

        // Base: before starting, we are flat with 0 profit for any j
        // (editorial trick: allow j>1 to start flat as well)
        for (int j = 1; j <= k + 1; ++j) {
            f[j][0] = 0;
        }

        for (int i = l; i < r; ++i) {
            int p = prices[i % n];
            // iterate j descending to avoid using updated values in the same day
            for (int j = k + 1; j > 0; --j) {
                // Close long or short -> go flat (complete a transaction)
                f[j][0] = max(f[j][0], max(f[j][1] + p, f[j][2] - p));
                // Open long from flat (spend p)
                f[j][1] = max(f[j][1], f[j - 1][0] - p);
                // Open short from flat (receive p)
                f[j][2] = max(f[j][2], f[j - 1][0] + p);
            }
        }

        return f[k + 1][0];
    }

public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();

        // Position of a global maximum element in the cyclic array
        int max_i = max_element(nums.begin(), nums.end()) - nums.begin();

        // Case 1: nums[max_i] is the first element of the linearized array
        long long ans1 = maximumProfitSegment(nums, max_i, max_i + n, k);

        // Case 2: nums[max_i] is the last element of the linearized array
        long long ans2 = maximumProfitSegment(nums, max_i + 1, max_i + 1 + n, k);

        return max(ans1, ans2);
    }
};

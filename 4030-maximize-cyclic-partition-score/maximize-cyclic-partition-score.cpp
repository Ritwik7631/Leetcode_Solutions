#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 3573: Best Time to Buy and Sell Stock V on a linear array
    long long maximumProfit(vector<int>& prices, int k) {
        int n = (int)prices.size();
        const long long NEG = LLONG_MIN / 4;

        // f[j][0] = flat
        // f[j][1] = holding long
        // f[j][2] = holding short
        // j = 1..k+1, final answer = f[k+1][0]
        vector<array<long long,3>> f(
            k + 2,
            {NEG, NEG, NEG}
        );

        // base: before any day, we can be flat with 0 profit
        for (int j = 1; j <= k + 1; ++j) {
            f[j][0] = 0;
        }

        for (int i = 0; i < n; ++i) {
            long long p = prices[i];
            // go j downwards to avoid reusing updated values in same day
            for (int j = k + 1; j > 0; --j) {
                // close long or short -> flat
                f[j][0] = max(f[j][0], max(f[j][1] + p, f[j][2] - p));
                // open long from flat
                f[j][1] = max(f[j][1], f[j - 1][0] - p);
                // open short from flat
                f[j][2] = max(f[j][2], f[j - 1][0] + p);
            }
        }

        return f[k + 1][0];
    }

    // 3743: cyclic version, no l/r, just two linearizations
    long long maximumScore(vector<int>& nums, int k) {
        int n = (int)nums.size();

        // index of a global maximum
        int max_i = max_element(nums.begin(), nums.end()) - nums.begin();

        // Case 1: nums[max_i] is first
        vector<int> arr1(n);
        for (int i = 0; i < n; ++i) {
            arr1[i] = nums[(max_i + i) % n];
        }

        // Case 2: nums[max_i] is last
        vector<int> arr2(n);
        for (int i = 0; i < n; ++i) {
            arr2[i] = nums[(max_i + 1 + i) % n];
        }

        long long ans1 = maximumProfit(arr1, k);
        long long ans2 = maximumProfit(arr2, k);
        return max(ans1, ans2);
    }
};

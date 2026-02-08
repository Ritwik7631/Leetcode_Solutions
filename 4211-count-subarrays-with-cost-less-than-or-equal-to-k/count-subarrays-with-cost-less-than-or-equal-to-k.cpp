#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = (int)nums.size();
        deque<int> maxdq; // indices, nums decreasing -> front is max
        deque<int> mindq; // indices, nums increasing -> front is min

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // push r into maxdq
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[r]) maxdq.pop_back();
            maxdq.push_back(r);

            // push r into mindq
            while (!mindq.empty() && nums[mindq.back()] >= nums[r]) mindq.pop_back();
            mindq.push_back(r);

            // shrink until valid
            while (l <= r) {
                long long mx = nums[maxdq.front()];
                long long mn = nums[mindq.front()];
                long long len = (long long)r - l + 1;
                __int128 cost = (__int128)(mx - mn) * (__int128)len;

                if (cost <= k) break;

                // remove l if it falls out
                if (!maxdq.empty() && maxdq.front() == l) maxdq.pop_front();
                if (!mindq.empty() && mindq.front() == l) mindq.pop_front();
                l++;
            }

            ans += (long long)r - l + 1;
        }

        return ans;
    }
};

#include <bits/stdc++.h>

using namespace std;

int fn(int i, int lastpick, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    // Base case: If we've moved before the first element, return 0.
    if (i < 0)
    {
        return 0;
    }

    // If the result is already computed, return it.
    if (dp[i][lastpick] != -1) return dp[i][lastpick];

    // Option 1: Do not pick the current element.
    int notpick = fn(i - 1, lastpick, arr, n, dp);

    // Option 2: Pick the current element (if it's valid to do so).
    int pick = INT_MIN;

    if (lastpick == n || arr[i] < arr[lastpick])
    {
        pick = fn(i - 1, i, arr, n, dp) + 1;
    }

    // Store and return the maximum of the two options.
    return dp[i][lastpick] = max(pick, notpick);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();

        // Initialize the dp array with -1 to indicate uncomputed states.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Start the recursion from the last index and an initial dummy 'lastpick' that is out of bounds.
        return fn(n - 1, n, arr, n, dp);
    }
};

#include <bits/stdc++.h>

using namespace std;

int fn(int i, int lastpick, vector<int>& arr, int n, vector<vector<int>> &dp)
{
    if(i >= n)
    {
        return 0;
    }

    if(dp[i][lastpick] != -1) return dp[i][lastpick];

    int notpick = fn(i+1, lastpick, arr, n, dp);

    int pick = INT_MIN;

    if(lastpick == 0 || arr[i-1] > arr[lastpick-1])
    {
        pick = fn(i+1, i, arr, n, dp) + 1;
    }

    return dp[i][lastpick] = max(pick, notpick);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));

        return fn(1, 0, arr, n+1, dp);
    }
};

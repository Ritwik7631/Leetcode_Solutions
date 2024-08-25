class Solution {
public:
    int fn(int i, int j, string &a, string &b, vector<vector<int>> &dp)
    {
        if(j < 0) return i+1;

        if(i < 0) return j+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j])
        {
            return dp[i][j] = fn(i-1, j-1, a, b,dp);
        }
        // insertion, deletion, replaction
        return dp[i][j] = min({1 + fn(i, j-1, a, b,dp), 1 + fn(i-1, j, a, b,dp), 1 + fn(i-1, j-1, a, b,dp)});
    }

    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));

        return fn(n-1, m-1, a, b, dp);
    }
};
class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        int n = triangle.size();
        if(i == triangle.size()-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX;

        int right = INT_MAX;

        if(i + 1 < n) left = fn(i+1, j, triangle, dp);

        if(i + 1 < n && j + 1 < triangle[i+1].size()) right = fn(i+1, j+1, triangle, dp);

        return dp[i][j] = min(left, right) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return fn(0, 0, triangle,dp);
    }
};
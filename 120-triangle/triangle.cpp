class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {
        if(i >= triangle.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int choice2 = INT_MAX;

        int choice1 = triangle[i][j] + fn(i+1, j, triangle,dp);

        if(i+1 < triangle.size() && j+1 < triangle[i+1].size()) choice2 = triangle[i][j] + fn(i+1, j+1, triangle,dp);

        return dp[i][j] = min(choice1, choice2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // fn(i,j) the minimum path from the top the of triangle to i and j
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return fn(0,0, triangle,dp);
    }
};
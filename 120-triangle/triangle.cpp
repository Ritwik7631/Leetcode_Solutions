class Solution {
public:
    // int fn(int i, int j, vector<vector<int>>& triangle, vector<vector<int>> &dp)
    // {
    //     if(i >= triangle.size()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int choice2 = INT_MAX;

    //     int choice1 = triangle[i][j] + fn(i+1, j, triangle,dp);

    //     if(i+1 < triangle.size() && j+1 < triangle[i+1].size()) choice2 = triangle[i][j] + fn(i+1, j+1, triangle,dp);

    //     return dp[i][j] = min(choice1, choice2);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        // fn(i,j) the minimum path from the top the of triangle to i and j
        // vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        // return fn(0,0, triangle,dp);

// ---------------------------------------------------------------------
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                int choice2 = INT_MAX;
                int choice1 = INT_MAX;

                if(j < triangle[i].size()) choice1 = triangle[i][j] + dp[i+1][j];

                if(i+1 < n && j+1 < triangle[i+1].size()) choice2 = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(choice1, choice2);
            }
        }

        return dp[0][0];
        


    }
};
class Solution {
public:
    // the int fn returns to you the minimum sum from 0,0 to i,j
    // int fn(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    // {
    //     cout << i << " " << j << endl;
    //     if(i == 0 && j == 0) return grid[0][0];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = INT_MAX;
    //     int left = INT_MAX;

    //     if(i-1>=0)
    //     {
    //         up = grid[i][j] + fn(i-1,j,grid,dp);
    //     }

    //     if(j-1>=0)
    //     {
    //         left = grid[i][j] + fn(i,j-1,grid,dp);
    //     }

    //     return dp[i][j] = min(up, left);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();

        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return fn(n-1,m-1,grid, dp);
// ----------------------------------------------------------------------------------------
        // Bottom up
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < n; i++)
        {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        for(int j = 1; j < m; j++)
        {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                int up = INT_MAX;
                int left = INT_MAX;

                if(i-1>=0)
                {
                    up = dp[i-1][j];
                }

                if(j-1>=0)
                {
                    left = dp[i][j-1];
                }

                dp[i][j] = min(up, left) + grid[i][j];    
            }
        }

        return dp[n-1][m-1];

        // Space Optimized
// ----------------------------------------------------------------------------
        // int n = grid.size();
        // int m = grid[0].size();

        // vector<int> prev(m, 0);
        // vector<int> cur(m, 0);

        // prev[0] = grid[0][0];

        // for(int j = 1; j < m; j++)
        // {
        //     prev[j] = grid[0][j] + prev[j-1];
        // }

        // for(int i = 1; i < n; i++)
        // {   
        //     cur[0] = prev[0] + grid[i][0];
        //     for(int j = 1; j < m; j++)
        //     {
        //         int up = INT_MAX;
        //         int left = INT_MAX;

        //         if(i-1>=0)
        //         {
        //             up = prev[j];
        //         }

        //         if(j-1>=0)
        //         {
        //             left = cur[j-1];
        //         }

        //         cur[j] = min(up, left) + grid[i][j];  
        //     }

        //     prev = cur;
        // }

        // return prev[m-1];

    }
};
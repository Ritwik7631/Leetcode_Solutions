class Solution {
public:
    // fn(i,j) return the number of unique paths from 0,0 to i,j
    // int fn(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    // {   
    //     if(grid[i][j] == 1) return 0;
    //     if(i == 0 && j == 0) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = 0;
    //     int left = 0;

    //     if(i-1 >= 0 && grid[i-1][j] == 0)
    //     {
    //         up = fn(i-1,j,grid,dp);
    //     }
        
    //     if(j-1>= 0 && grid[i][j-1] == 0)
    //     {
    //         left = fn(i,j-1,grid,dp);
    //     }
        

    //     return dp[i][j] = up + left;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();

        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return fn(n-1,m-1,grid,dp);
// ---------------------------------------------------------------------------
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int> (m, 0));

        // if(grid[n-1][m-1] == 1 || grid[0][0] == 1) return 0;

        // dp[0][0] = 1;

        // for(int i = 1; i < n; i++)
        // {
        //     if(grid[i][0] == 0)
        //     {
        //         dp[i][0] = dp[i-1][0];
        //     }
        // }

        // for(int j = 1; j < m; j++)
        // {
        //     if(grid[0][j] == 0)
        //     {
        //         dp[0][j] = dp[0][j-1];
        //     }
        // }

        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 1; j < m; j++)
        //     {
        //         int up = 0;
        //         int left = 0;

        //         if(i-1 >= 0 && grid[i-1][j] == 0)
        //         {
        //             up = dp[i-1][j];
        //         }
                
        //         if(j-1 >= 0 && grid[i][j-1] == 0)
        //         {
        //             left = dp[i][j-1];
        //         }
                

        //         dp[i][j] = up + left;
        //     }
        // }

        // return dp[n-1][m-1];

// -------------------------------------------------------------------
        int n = grid.size();
        int m = grid[0].size();

        if(grid[n-1][m-1] == 1 || grid[0][0] == 1) return 0;

        vector<int> prev(m, 0);
        vector<int> cur(m, 0);

        prev[0] = 1;

        for(int j = 1; j < m; j++)
        {
            if(grid[0][j] == 1)
            {
                prev[j] = 0;
            }
            else
            {
                prev[j] = prev[j-1];
            }
        }

        for(int i = 1; i < n; i++)
        {
            if (grid[i][0] == 1) {
                cur[0] = 0;  // Obstacle, no path
            } else {
                cur[0] = prev[0];  // No obstacle, inherit the value from the cell above
            }

            for(int j = 1; j < m; j++)
            {
                int up = 0;
                int left = 0;

                if(i-1 >= 0 && grid[i-1][j] == 0)
                {
                    up = prev[j];
                }
                
                if(j-1 >= 0 && grid[i][j-1] == 0)
                {
                    left = cur[j-1];
                }
                

                cur[j] = up + left;
            }

            prev = cur;
        }

        return prev[m-1];


    }
};
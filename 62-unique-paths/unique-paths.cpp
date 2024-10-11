class Solution {
public:
    // int fn(int i, int j, vector<vector<int>> &dp)
    // {
    //     if(i == 0 && j == 0) return 1;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int left = 0, up = 0;

    //     if(j - 1 >= 0) left = fn(i, j-1, dp);

    //     if(i - 1 >= 0) up = fn(i-1, j, dp);

    //     return dp[i][j] = up + left; 
    // }

    int uniquePaths(int n, int m) {
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return fn(n-1, m-1, dp);
// ------------------------------------------------------

        long long d = n-1;

        long long numerator = (m);

        long long ans = 1;
        
        for(int r = 1; r <= d; r++)
        {
            ans = ans * numerator;

            ans = ans / r;

            numerator++;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> rdel{1,0,-1,0};
    vector<int> cdel{0,-1,0,1};
    int dfs(vector<int> curr, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(dp[curr[0]][curr[1]] != -1) return dp[curr[0]][curr[1]];

        int longest = 1;

        for(int d = 0; d < 4; d++)
        {
            int nr = curr[0] + rdel[d];
            int nc = curr[1] + cdel[d];

            if(nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix[0].size() && matrix[nr][nc] > matrix[curr[0]][curr[1]])
            {
                longest = max(longest, 1 + dfs({nr,nc}, matrix, dp));
            }
        }

        return dp[curr[0]][curr[1]] = longest;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int> (m, -1));
        vector<int> path;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int longest = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                longest = max(longest, dfs({i,j}, matrix, dp));
            }
        }

        return longest;
    }
};
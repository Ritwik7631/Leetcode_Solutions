class Solution {
public:
    vector<int> rdel{1,0,-1,0};
    vector<int> cdel{0,-1,0,1};

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int& area)
    {
        area += 1;
        vis[i][j] = 1;

        for(int d = 0; d < 4; d++)
        {
            int nr = i + rdel[d];
            int nc = j + cdel[d];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && vis[nr][nc] == 0)
            {
                dfs(nr,nc,vis,grid,area);
            }
        }
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(i,j,vis,grid,area);
                    mx = max(mx, area);
                }
            }
        }

        return mx;
    }
};
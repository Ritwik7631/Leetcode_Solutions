class Solution {
public:
    int bfs(vector<int> curr, vector<vector<int>>& grid, vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;

        q.push({curr[0], curr[1]});

        int perimeter = 0;

        vis[curr[0]][curr[1]] = 1;

        while(!q.empty())
        {
            pair<int,int> x = q.front();
            q.pop();

            vector<int> rdel{1, 0, -1, 0};
            vector<int> cdel{0, -1, 0, 1};

            for(int d = 0; d < 4; d++)
            {
                int nr = x.first + rdel[d];
                int nc = x.second + cdel[d];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && (grid[nr][nc] == 0))
                {
                    perimeter++;
                }

                if(!(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()))
                {
                    perimeter++;
                }

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && vis[nr][nc] == 0)
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int> (m, 0));


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return bfs({i,j}, grid, visited);
                }
            }
        }

        return 0;
    }
};
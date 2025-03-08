class Solution {
public:
    void bfs(vector<int> curr, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;

        q.push({curr[0], curr[1]});

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

                if(nr >= 0 && nr < grid.size() &&
                   nc >= 0 && nc < grid[0].size() &&
                   vis[nr][nc] == 0 && grid[nr][nc] == '1')
                {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs({i,j}, grid, vis);
                }
            }
        }

        return count;
    }
};
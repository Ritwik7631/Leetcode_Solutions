class Solution {
public:
    int findpar(vector<int> &parent, int X)
    {
        if(parent[X] == X) return X;

        return parent[X] = findpar(parent, parent[X]);
    }

    void merge(vector<int> &parent, int X, int Y)
    {
        int upx = findpar(parent, X);
        int upy = findpar(parent, Y);
        if(upx == upy) return;

        parent[upy] = upx;
    }

    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size(); 
       vector<int> parents(n*n);
        unordered_map<int, pair<int,int>> mp;
       for(int i = 0; i < n; i++)
       {
            for(int j = 0; j < n; j++)
            {
                parents[grid[i][j]] = grid[i][j];
                mp[grid[i][j]] = {i, j};
            }   
       }
       int a = grid[0][0];
       int b = grid[n-1][n-1];

       int t = 0;

       vector<int> rdel = {-1, 0, 1, 0};
       vector<int> cdel = {0, 1, 0, -1};

       while(findpar(parents, a) != findpar(parents, b))
       {    
            t++;
            int x = mp[t].first;
            int y = mp[t].second;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + rdel[i];
                int ny = y + cdel[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    if(grid[nx][ny] <= grid[x][y])
                    {
                        merge(parents, grid[x][y], grid[nx][ny]);
                    }
                }
            }
       }

       return t;

    }
};
class Solution {
public:
    int findpar(vector<int> &parent, int X)
    {
        if(parent[X] == X) return X;

        return parent[X] = findpar(parent, parent[X]);
    }

    void merge(vector<int> &parent, vector<int> &size, int X, int Y)
    {
        int upx = findpar(parent, X);
        int upy = findpar(parent, Y);
        if(upx == upy) return;

        parent[upy] = upx;

        size[upx] += size[upy];
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n*n);

        for(int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        vector<int> size(n*n, 1);

        vector<int> rdel = {-1, 0, 1, 0};
        vector<int> cdel = {0, 1, 0, -1};
        // merged all ones together
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0) continue;

                int val = i*n + j;

                int a = findpar(parent, val);

                for(int k = 0; k < 4; k++)
                {
                    int nx = i + rdel[k];
                    int ny = j + cdel[k];

                    if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if(grid[nx][ny] == 1)
                        {
                            int val2 = nx*n + ny;

                            int b = findpar(parent, val2);

                            if(a != b)
                            {
                                merge(parent, size, a, b);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) continue;

                set<int> components;

                for(int k = 0; k < 4; k++)
                {
                    int nx = i + rdel[k];
                    int ny = j + cdel[k];
                    
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if(grid[nx][ny] == 1)
                        {
                            int val = nx*n + ny;

                            components.insert(findpar(parent, val));
                        }
                    }
                }

                int total = 0;

                for(auto it : components)
                {
                    total += size[it];
                }

                ans = max(ans, total + 1);
            }
        }
        if(ans == 0) return n*n;

        return ans;
    }
};
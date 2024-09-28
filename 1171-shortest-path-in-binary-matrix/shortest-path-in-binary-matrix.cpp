class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        set<pair<int, pair<int,int>>> st;

        if(grid[0][0] == 1) return -1;

        st.insert({0,{0,0}});
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 0;

        while(!st.empty())
        {
            auto it = st.begin();

            pair<int, pair<int,int>> pr = *it;

            pair<int,int> node = pr.second;
            int src_parent = pr.first;
            st.erase(it);

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if(i == 0 && j == 0) continue;

                    int x = node.first + i;
                    int y = node.second + j;

                    if(x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        if(dist[x][y] > src_parent + 1)
                        {
                            if(dist[x][y] != INT_MAX) st.erase({dist[x][y],  {x,y}});

                            dist[x][y] = src_parent + 1;

                            st.insert({dist[x][y], {x,y}});
                        }
                    }


                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX) return -1;

        return dist[n-1][n-1] + 1;

    }
};
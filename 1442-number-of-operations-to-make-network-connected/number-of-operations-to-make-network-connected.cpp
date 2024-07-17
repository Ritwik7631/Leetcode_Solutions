class Solution {
public:
    void DFS(int i, vector<vector<int>> &grph, vector<int> &vis)
    {
        vis[i] = 1;
        for(auto a : grph[i])
        {
            if(vis[a] == 0)
            {
                DFS(a, grph, vis);
            }
        }

        return;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // determine number of coponents
        // determine number of extra edges IN ALL components
        // if(E >= components - 1) return components - 1 ans
        // else -1

        if(connections.size() < n - 1) return -1;

        vector<vector<int>> grph(n);

        for(int i = 0; i < connections.size(); i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];

            grph[a].push_back(b);
            grph[b].push_back(a);
        }

        vector<int> vis(n,0);

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                DFS(i, grph, vis);
                count++;
            }
        }

        if(connections.size() >= count - 1) return count - 1;
        else return -1;
    }   
};
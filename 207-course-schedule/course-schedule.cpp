class Solution {
public:
    // true means no cycle
    // false means there is cycle and not topologically sortable
    bool topo_sort_dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path_vis)
    {
        vis[i] = 1;
        path_vis[i] = 1;

        for(auto a : adj[i])
        {
            if(vis[a] == 0)
            {
                if(!topo_sort_dfs(a, adj, vis, path_vis))
                {
                    return false;
                }
            }
            else if(vis[a] == 1)
            {
                if(path_vis[a] == 1)
                {
                    return false;
                }
            }
        }

        path_vis[i] = 0;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        vector<int> path_vis(n,0);

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0 && !topo_sort_dfs(i,adj,vis,path_vis)) return false;
        }

        return true;
    }
};
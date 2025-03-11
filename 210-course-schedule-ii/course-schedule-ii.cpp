class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& path_vis, vector<vector<int>>& adj, vector<int>& order)
    {
        vis[i] = 1;
        path_vis[i] = 1;

        for(auto a : adj[i])
        {
            if(!vis[a])
            {
                if(!dfs(a, vis, path_vis, adj, order)) return false;
            }
            else
            {
                if(path_vis[a] == 1)
                {
                    return false;
                }
            }       
        }

        order.push_back(i);

        path_vis[i] = 0;

        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < prereq.size(); i++)
        {
            int a = prereq[i][0];
            int b = prereq[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(n);
        vector<int> path_vis(n);
        vector<int> order;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(!dfs(i, vis, path_vis, adj, order))
                {
                    return {};
                }
            }
        }

        if(!order.empty())
        {
            reverse(order.begin(), order.end());
            return order;
        }

        return {};
    }
};
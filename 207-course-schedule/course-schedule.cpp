class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<int>& path_vis, vector<vector<int>>& adj)
    {
        vis[i] = 1;
        path_vis[i] = 1;

        for(auto a : adj[i])
        {
            if(!vis[a])
            {
                if(!dfs(a, vis, path_vis, adj)) return false;
            }
            else
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

    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < prereq.size(); i++)
        {
            int a = prereq[i][0];
            int b = prereq[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(n);
        vector<int> path_vis(n);

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(!dfs(i, vis, path_vis, adj)) return false;
            }
        }

        return true;
    }
};
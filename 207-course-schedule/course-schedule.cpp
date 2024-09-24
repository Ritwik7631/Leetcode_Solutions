class Solution {
public:
    bool DFS(int i, vector<int> &vis, vector<int> &path_vis, vector<vector<int>> &adj)
    {
        vis[i] = 1;
        path_vis[i] = 1;
        bool flag = false;
        for(auto a : adj[i])
        {
            if(vis[a] == 0)
            {
                if(DFS(a, vis, path_vis, adj)) return true;
            }
            else if(vis[a] != 0 && path_vis[a] == 1)
            {
                return true;
            }
        }

        path_vis[i] = 0;

        return flag;
    }

    bool canFinish(int numCourses, vector<vector<int>>& x) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> path_vis(n, 0);

        vector<vector<int>> adj(n);

        for(int i = 0; i < x.size(); i++)
        {
            int a = x[i][0];
            int b = x[i][1];

            adj[b].push_back(a);
        }

        bool flag = false;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                flag = flag || DFS(i, vis, path_vis, adj); 
                // Think of DFS to see whether or not a cycle exists
            }
        }

        return !flag;
    }
};
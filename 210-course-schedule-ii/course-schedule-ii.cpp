class Solution {
public:
    bool DFS(int i, vector<int> &vis, vector<int> &path_vis, vector<vector<int>> &adj, vector<int> &ans)
    {
        vis[i] = 1;
        path_vis[i] = 1;

        for(auto a : adj[i])
        {
            if(vis[a] == 0)
            {
                if(DFS(a, vis, path_vis, adj, ans)) return true;;
            }
            else if(path_vis[a] == 1)
            {
                return true;
            }
        }

        ans.push_back(i);
        path_vis[i] = 0;
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& x) {
// topo sort using BFS/ Kahn's algorithm
        // vector<int> ans;
        // vector<int> inDegree(n, 0);
        // queue<int> q;
        // vector<vector<int>> adj(n);

        // for(int i = 0; i < x.size(); i++)
        // {
        //     int a = x[i][0];
        //     int b = x[i][1];

        //     adj[b].push_back(a);
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     for(auto c : adj[i])
        //     {
        //         inDegree[c]++;
        //     }
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     if(inDegree[i] == 0)
        //     {
        //         q.push(i);
        //     }
        // }

        // while(!q.empty())
        // {
        //     int val = q.front();
        //     q.pop();
        //     ans.push_back(val);

        //     for(auto a : adj[val])
        //     {
        //         inDegree[a]--;

        //         if(inDegree[a] == 0)
        //         {
        //             q.push(a);
        //         }
        //     }
        // }

        // int total = accumulate(inDegree.begin(), inDegree.end(), 0);

        // if(total != 0)
        // {
        //     return {};
        // }

        // return ans;
// Topo Sort using DFS

        vector<vector<int>> adj(n);

        for(int i = 0; i < x.size(); i++)
        {
            int a = x[i][0];
            int b = x[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        vector<int> path_vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                if(DFS(i, vis, path_vis, adj, ans)) return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
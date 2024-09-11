class Solution {
public:
    void DFS(int node, vector<bool> &visited, vector<int> adj[])
    {
        visited[node] = true;

        for(auto a : adj[node])
        {
            if(!visited[a]) DFS(a, visited, adj);
        }

        return;
    }
    // void BFS(int node, vector<bool> &visited, vector<int> adj[])
    // {
    //     visited[node] = true;

    //     queue<int> q;

    //     q.push(node);

    //     while(!q.empty())
    //     {
    //         int x = q.front();
    //         q.pop();
    //         for(auto a : adj[x])
    //         {
    //             if(!visited[a])
    //             {
    //                 visited[a] = true;
    //                 q.push(a);
    //             }
    //         }
    //     }

    //     return;
    // }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                }

            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                DFS(i, visited, adj);
            }
        }

        return count;
    }
};
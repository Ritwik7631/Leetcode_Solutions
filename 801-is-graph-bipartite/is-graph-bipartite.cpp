class Solution {
public:
    bool dfs(int i, int parent, vector<vector<int>>& adj, vector<int>& colors)
    {
        for(auto a : adj[i])
        {
            if(a == parent) continue;

            if(colors[a] == 2)
            {
                colors[a] = !colors[i];
                if(!dfs(a,i,adj,colors)) return false;
            }
            else
            {
                if(colors[i] == colors[a]) return false;
            }
            
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        // do one dfs to paint red blue
        // do another dfs to check if there are no consecutive red or blue neighbors
        
        int n = adj.size();
        vector<int> colors(n, 2);

        // 0 red
        // 1 blue
        // 2 uncolored

        for (int i = 0; i < n; i++) {
            if (colors[i] == 2)  
            { 
                colors[i] = 0;
                if (!dfs(i, -1, adj, colors)) return false;
            }
        }
        return true;
    }
};
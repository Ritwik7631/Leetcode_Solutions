class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        // construct graph
        // use prim's algoritm to find the edges that are part of minimum spanning tree
        // sort the edges in descending order
        // pick the edge at the k-1 index, we are logically removing the edges that come prior

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> min_weight(n, INT_MAX), parent(n, -1);
        vector<bool> inMST(n, false);
        

        multiset<pair<int,int>> ms;
        ms.insert({0,0});
        min_weight[0] = 0;

        while(!ms.empty()){
            auto it = *ms.begin();
            ms.erase(it);
            int u = it.second;

            if(inMST[u]) continue;

            inMST[u] = true;

            for(auto a : adj[u]){
                int v = a.first;
                int w = a.second;

                if(!inMST[v] && w < min_weight[v]){
                    if(min_weight[v] != INT_MAX) ms.erase(ms.find({min_weight[v],v}));

                    min_weight[v] = w;
                    parent[v] = u;
                    ms.insert({w, v});
                }
            }
        }

        vector<int> MST_Weights;

        for(int i = 1; i < n; i++){
            if(parent[i] != -1){
                MST_Weights.push_back(min_weight[i]);
            }
        }

        sort(MST_Weights.begin(), MST_Weights.end(), greater<int>());

        if(k-1 >= MST_Weights.size()) return 0;

        return MST_Weights[k-1];
    }   
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> min_weight(n, 1e9), parent(n, -1); 
        vector<bool> inMST(n, false);

        multiset<pair<int,int>> ms; // weight, node

        min_weight[0] = 0;
        ms.insert({0,0});

        while(!ms.empty()){
            auto it = ms.begin();
            int u = it->second;
            ms.erase(it);

            if(inMST[u]) continue;
            inMST[u] = true;

            for(auto &it : adj[u]){
                int v = it.first;
                int wt = it.second;
                if(!inMST[v] && wt < min_weight[v]){
                    if(min_weight[v] != 1e9) ms.erase(ms.find({min_weight[v], v}));
                    min_weight[v] = wt;
                    parent[v] = u;
                    ms.insert({wt, v});
                }
            }
        }

        vector<int> mstW;

        for(int v = 1; v < n; v++){
            if(parent[v] != -1){
                mstW.push_back(min_weight[v]);
            }
        }

        sort(mstW.begin(), mstW.end(), greater<int>());
        // number of removals is k-1 if u want k components
        // if number of edge removals >= the number of edges in MST then return 0
        if(k - 1 >= (int)mstW.size()) return 0;

        return mstW[k-1];
    }
};
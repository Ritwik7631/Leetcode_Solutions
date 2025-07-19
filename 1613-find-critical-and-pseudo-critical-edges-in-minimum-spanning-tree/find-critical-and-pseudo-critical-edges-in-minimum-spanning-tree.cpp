class Solution {
public:
    int nm;

    int mst_weight_v1(int &ignore, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(nm);
        for(int i = 0; i < edges.size(); i++){
            if(i == ignore) continue;
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int> min_weight(nm, INT_MAX), parent(nm, -1);
        vector<bool> in_MST(nm, false);
        multiset<pair<int,int>> ms; // (weight, node)

        ms.insert({0,0});
        min_weight[0] = 0;

        int MST_Weight = 0;
        int cnt = 0;  // track how many nodes we've added

        // stop once we've added all nodes
        while(!ms.empty() && cnt < nm){
            auto it = *ms.begin(); ms.erase(ms.begin());
            int u = it.second, wt = it.first;
            if(in_MST[u]) continue;
            in_MST[u] = true;
            MST_Weight += wt;
            cnt++;  // increment when we actually add u to the MST

            for(auto &a : adj[u]){
                int v = a.first, w = a.second;
                if(!in_MST[v] && w < min_weight[v]){
                    if(min_weight[v] != INT_MAX)
                        ms.erase(ms.find({min_weight[v], v}));
                    min_weight[v] = w;
                    parent[v] = u;
                    ms.insert({w, v});
                }
            }
        }

        // if we didn't reach all nodes, graph was disconnected without 'ignore'
        return (cnt == nm ? MST_Weight : INT_MAX);
    }

    int mst_weight_v2(int &include, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(nm);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int u0 = edges[include][0],
            v0 = edges[include][1],
            w0 = edges[include][2];

        vector<bool> in_MST(nm, false);
        multiset<pair<int,int>> ms; // (weight, node)

        // force-include edge (u0,v0)
        in_MST[u0] = in_MST[v0] = true;
        int MST_Weight = w0, cnt = 2;

        for(auto &p : adj[u0])
            if(!in_MST[p.first]) ms.insert({p.second, p.first});
        for(auto &p : adj[v0])
            if(!in_MST[p.first]) ms.insert({p.second, p.first});

        while(!ms.empty() && cnt < nm){
            auto it = *ms.begin(); ms.erase(ms.begin());
            int u = it.second, wt = it.first;
            if(in_MST[u]) continue;
            in_MST[u] = true;
            MST_Weight += wt;
            cnt++;
            for(auto &a : adj[u]){
                int v = a.first, w = a.second;
                if(!in_MST[v]) ms.insert({w, v});
            }
        }

        return (cnt == nm ? MST_Weight : INT_MAX);
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        nm = n;
        int ignore = -1;
        
        int baseline = mst_weight_v1(ignore, edges);

        vector<int> critical_edges, pseudo_critical_edges;
        for(int i = 0; i < edges.size(); i++){
            // test for critical
            ignore = i;
            if(mst_weight_v1(ignore, edges) > baseline) {
                critical_edges.push_back(i);
            }
            else {
                // test for pseudo-critical
                int include = i;
                if(mst_weight_v2(include, edges) == baseline)
                    pseudo_critical_edges.push_back(i);
            }
        }

        return { critical_edges, pseudo_critical_edges };
    }
};

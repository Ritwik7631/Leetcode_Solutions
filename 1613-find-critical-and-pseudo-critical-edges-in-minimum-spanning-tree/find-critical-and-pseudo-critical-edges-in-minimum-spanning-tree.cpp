#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nm;

    // Lazy Prim’s using multiset, skipping edge index = ignore
    int mst_weight_v1(int ignore, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(nm);
        for (int i = 0; i < edges.size(); ++i) {
            if (i == ignore) continue;
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vector<bool> inMST(nm, false);
        multiset<pair<int,int>> ms;  // (weight, node)
        ms.insert({0, 0});

        int total = 0, cnt = 0;
        while (!ms.empty() && cnt < nm) {
            auto it = ms.begin();
            int w = it->first, u = it->second;
            ms.erase(it);
            if (inMST[u]) continue;
            inMST[u] = true;
            total += w;
            ++cnt;
            for (auto &p : adj[u]) {
                if (!inMST[p.first])
                    ms.insert({p.second, p.first});
            }
        }
        return (cnt == nm ? total : INT_MAX);
    }

    // Lazy Prim’s using multiset, pre-including edge index = include
    int mst_weight_v2(int include, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(nm);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int u0 = edges[include][0],
            v0 = edges[include][1],
            w0 = edges[include][2];

        vector<bool> inMST(nm, false);
        multiset<pair<int,int>> ms;  // (weight, node)

        // force-include (u0,v0)
        inMST[u0] = inMST[v0] = true;
        int total = w0, cnt = 2;

        for (auto &p : adj[u0])
            if (!inMST[p.first])
                ms.insert({p.second, p.first});
        for (auto &p : adj[v0])
            if (!inMST[p.first])
                ms.insert({p.second, p.first});

        while (!ms.empty() && cnt < nm) {
            auto it = ms.begin();
            int w = it->first, u = it->second;
            ms.erase(it);
            if (inMST[u]) continue;
            inMST[u] = true;
            total += w;
            ++cnt;
            for (auto &p : adj[u]) {
                if (!inMST[p.first])
                    ms.insert({p.second, p.first});
            }
        }
        return (cnt == nm ? total : INT_MAX);
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,
                                                          vector<vector<int>>& edges) {
        nm = n;
        int baseline = mst_weight_v1(-1, edges);

        vector<int> critical, pseudo;
        for (int i = 0; i < edges.size(); ++i) {
            if (mst_weight_v1(i, edges) > baseline) {
                critical.push_back(i);
            } else if (mst_weight_v2(i, edges) == baseline) {
                pseudo.push_back(i);
            }
        }
        return { critical, pseudo };
    }
};

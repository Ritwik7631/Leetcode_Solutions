#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nm;

    // Lazy Prim’s, skipping edge index = ignore
    int mst_weight_v1(int ignore, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(nm);
        for (int i = 0; i < edges.size(); ++i) {
            if (i == ignore) continue;
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        vector<bool> inMST(nm, false);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        pq.emplace(0, 0);  // (weight, node)

        int total = 0, cnt = 0;
        while (!pq.empty() && cnt < nm) {
            auto [w, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            total += w;
            ++cnt;
            for (auto &p : adj[u]) {
                if (!inMST[p.first])
                    pq.emplace(p.second, p.first);
            }
        }
        return (cnt == nm ? total : INT_MAX);
    }

    // Lazy Prim’s, pre-including edge index = include
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
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // force-include (u0,v0)
        inMST[u0] = inMST[v0] = true;
        int total = w0, cnt = 2;

        for (auto &p : adj[u0])
            if (!inMST[p.first])
                pq.emplace(p.second, p.first);
        for (auto &p : adj[v0])
            if (!inMST[p.first])
                pq.emplace(p.second, p.first);

        while (!pq.empty() && cnt < nm) {
            auto [w, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true;
            total += w;
            ++cnt;
            for (auto &p : adj[u]) {
                if (!inMST[p.first])
                    pq.emplace(p.second, p.first);
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
            // 1) critical?
            if (mst_weight_v1(i, edges) > baseline) {
                critical.push_back(i);
            }
            // 2) pseudo (only if not critical)
            else if (mst_weight_v2(i, edges) == baseline) {
                pseudo.push_back(i);
            }
        }
        return { critical, pseudo };
    }
};

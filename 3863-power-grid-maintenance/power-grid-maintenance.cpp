#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector< set<int> > active;          // keeps active stations per root

    void init(int n){
        parent.resize(n+1);
        active.resize(n+1);
        for (int i = 1; i <= n; ++i){
            parent[i] = i;
            active[i].insert(i);        // every station starts online
        }
    }

    int find(int x){
        return x==parent[x] ? x : parent[x]=find(parent[x]);
    }

    void unite(int x,int y){
        int px = find(x), py = find(y);
        if (px==py) return;
        if (active[px].size() < active[py].size()) swap(px, py);
        parent[py] = px;
        active[px].merge(active[py]);   // move all of py’s actives into px
    }

    vector<int> processQueries(int c,
                               vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        init(c);
        for (auto &e: connections)
            unite(e[0], e[1]);

        vector<int> ans;
        vector<char> online(c+1, 1);     // 1 = active, 0 = offline

        for (auto &q : queries){
            int type = q[0], v = q[1], r = find(v);

            if (type == 1) {
                if (online[v]) {
                    // ★ FIX: return v itself when it's still online
                    ans.push_back(v);
                } else {
                    // otherwise smallest active in its component
                    if (!active[r].empty())
                        ans.push_back(*active[r].begin());
                    else
                        ans.push_back(-1);
                }
            } else {
                // type‐2: deactivate v
                if (online[v]) {
                    online[v] = 0;
                    active[r].erase(v);
                }
            }
        }
        return ans;
    }
};

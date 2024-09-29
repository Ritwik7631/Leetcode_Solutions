#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> grph(n);

        for(int i = 0; i < roads.size(); i++)
        {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];
            grph[a].push_back({b,c});
            grph[b].push_back({a,c});
        }

        set<pair<ll,ll>> st;

        st.insert({0, 0});

        vector<ll> dist(n, 1e12);
        vector<ll> unique(n, 0);

        dist[0] = 0;
        unique[0] = 1;

        while(!st.empty())
        {
            auto it = st.begin();
            pair<ll,ll> pr = *it;
            ll current_dist = pr.first;
            ll parent = pr.second;
            ll unique_parent = unique[parent];
            st.erase(it);

            for(auto a : grph[parent])
            {
                ll child = a.first;
                ll new_dist = a.second;

                if(dist[child] > current_dist + new_dist)
                {
                    if(dist[child] != INT_MAX) st.erase({dist[child], child});

                    dist[child] = current_dist + new_dist;

                    unique[child] = unique_parent;

                    st.insert({dist[child], child});
                }
                else if(dist[child] == current_dist + new_dist)
                {
                    unique[child] = (unique[child] % mod + unique_parent % mod) % mod;
                }
            }
        }
        
        return unique[n-1] % mod;

    }
};
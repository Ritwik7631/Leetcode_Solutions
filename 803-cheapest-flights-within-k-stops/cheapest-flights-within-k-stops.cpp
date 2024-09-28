class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        set<pair<int, pair<int,int>>> st;

        // stops, node, dist

        st.insert({-1, {src, 0}});

        vector<vector<pair<int,int>>> grph(n);

        for(int i = 0; i < flights.size(); i++)
        {
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];
            grph[a].push_back({b,c});
        }

        for(int i = 0; i < n; i++)
        {
            cout << i << " ";
            for(auto b : grph[i]) cout << b.first << " " << b.second << "|";
            cout << endl; 
        }

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        while(!st.empty())
        {
            auto it = st.begin();
            pair<int, pair<int,int>> x = *it;

            int stops = x.first;
            int node = x.second.first;
            int old_dist = x.second.second;

            st.erase(it);

            cout << "parent: " << node << endl;
            cout << "child: " << endl;
            for(auto a : grph[node])
            {
                int child = a.first;
                int new_dist = a.second;
                cout << child << " ";
                int new_stops = stops + 1;

                if(new_stops <= k)
                {
                    if(dist[child] > old_dist + new_dist)
                    {
                        dist[child] = old_dist + new_dist;

                        st.insert({new_stops, {child, dist[child]}});
                    }
                }
            }
            cout << endl;
        }

        if(dist[dst] == INT_MAX) return -1;

        return dist[dst];
    }
};
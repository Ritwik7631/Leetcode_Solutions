#define ll long long
class Solution {
public:
    // state 0 means do not include parent
    // state 1 means include parent
    ll dfs(int node, int state, vector<vector<pair<ll,ll>>> &adj, vector<vector<ll>> &dp, int k, int parent, int p_weight)
    {
        if(dp[node][state] != -1) return dp[node][state];

        vector<pair<ll,ll>> temp; // weight, node
        for(auto a : adj[node])
        {
            if(a.first != parent)
            {
                ll x = dfs(a.first, 0, adj, dp, k, node, a.second);
                ll y = dfs(a.first, 1, adj, dp, k, node, a.second);
                temp.push_back(make_pair(y - x, a.first));
            }
        }

        sort(temp.rbegin(), temp.rend());
        ll tempsize = temp.size();
        ll ans = 0;
        if(state == 0)
        {
            for(int i = 0; i < temp.size(); i++)
            {
                if(i < k && dp[temp[i].second][1] > dp[temp[i].second][0])
                {
                    ans += dp[temp[i].second][1];
                }
                else
                {
                    ans += dp[temp[i].second][0];
                }
            }
        }
        else
        {
            ans += p_weight;

            for(int i = 0; i < temp.size(); i++)
            {
                if(i < k-1 && dp[temp[i].second][1] > dp[temp[i].second][0])
                {
                    ans += dp[temp[i].second][1];
                }
                else
                {
                    ans += dp[temp[i].second][0];
                }
            }
        }

        return dp[node][state] = ans;

    }

    ll maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<ll>> dp(n+1, vector<ll> (2, -1));
        vector<vector<pair<ll,ll>>> adj(n+1);

        for(int i = 0; i < edges.size(); i++)
        {
            ll a = edges[i][0];
            ll b = edges[i][1];
            ll w = edges[i][2];

            adj[a].push_back(make_pair(b,w));
            adj[b].push_back(make_pair(a,w));
        }

        return dfs(0, 0, adj, dp, k, -1, 0);

    }
};
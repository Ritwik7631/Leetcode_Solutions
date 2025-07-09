class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &connected_ids, unordered_map<int, int> &node_to_component, int &component_id){
        connected_ids.push_back(i);
        vis[i] = 1;
        node_to_component[i] = component_id;
        for(auto a : adj[i]){
            if(vis[a] == -1){
                dfs(a, adj, vis, connected_ids, node_to_component, component_id);
            }
        }

        return;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // precompute a vector of size n
        // I have a vector arr[i] where arr[i] returns the smallest id connected to it starting from index i
        // identify components/power grid

        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> node_to_component;
        vector<vector<int>> adj(c+1);
        vector<bool> status(c+1, true);

        vector<int> ans;

        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        int component_id = 1;
        vector<int> vis(c+1, -1);

        for(int i = 1; i <= c; i++){
            if(vis[i] == -1){
                vector<int> connected_ids;
                dfs(i, adj, vis, connected_ids, node_to_component, component_id);

                sort(connected_ids.rbegin(), connected_ids.rend());
                mp[component_id] = connected_ids;
                component_id++;
            }
        }

        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == 1){
                if(status[queries[i][1]] == true) ans.push_back(queries[i][1]);
                else{
                    if(mp[node_to_component[queries[i][1]]].empty()) ans.push_back(-1);
                    else{
                        ans.push_back(mp[node_to_component[queries[i][1]]].back());
                    }
                }
            }
            else{
                status[queries[i][1]] = false;

                while(!mp[node_to_component[queries[i][1]]].empty() && status[mp[node_to_component[queries[i][1]]].back()] == false){
                    mp[node_to_component[queries[i][1]]].pop_back();
                }
            }
        }

        return ans;
    }
};
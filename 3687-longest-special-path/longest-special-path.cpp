class Solution {
public:
    int longest_special_path = 0;
    int min_counter = INT_MAX;

    void dfs(int i, int parent, vector<vector<pair<int,int>>> &adj, vector<int> &nums, int pathSum, int start, int end, unordered_map<int,int> &last_seen, vector<int> &path)
    {
        // int prev_last_seen = last_seen.count(nums[i]) ? last_seen[nums[i]]: -1;

        int prev_last_seen;

        if(last_seen.count(nums[i]))
        {
            prev_last_seen = last_seen[nums[i]];
        }
        else
        {
            prev_last_seen = -1;
        }
        
        while(start <= prev_last_seen)
        {
            pathSum -= path[start];
            start++;
        }

        if(pathSum > longest_special_path)
        {
            longest_special_path = pathSum;
            min_counter = end - start + 1;
        }
        else if(pathSum == longest_special_path)
        {
            min_counter = min(min_counter, end-start+1);
        }

        last_seen[nums[i]] = end;

        for(auto a : adj[i])
        {
            if(a.first == parent) continue;

            path.push_back(a.second);
            dfs(a.first, i, adj, nums, pathSum + a.second, start, end+1, last_seen, path);
            path.pop_back();
        }

        // when we have visited every branch then we restore the last seen

        last_seen[nums[i]] = prev_last_seen;

    }


    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {

        unordered_map<int,int> last_seen;

        vector<int> path;

        int n = nums.size();

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];

            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }

//void dfs(int i, int parent, vector<vector<pair<int,int>>> &adj, vector<int> &nums, int pathSum, int start, int end, unordered_map<int,int> &last_seen, vector<int> &path)

        dfs(0, -1, adj, nums, 0, 0, 0, last_seen, path);

        return {longest_special_path, min_counter};
    }
};
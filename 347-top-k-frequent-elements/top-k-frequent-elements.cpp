class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_maps have tc of O(n)

        unordered_map<int,int> mp;

        for(auto a : nums)
        {
            mp[a]++;
        }

        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        for(auto [val,freq] : mp)
        {
            bucket[freq].push_back(val);
        }

        int x = bucket.size();

        vector<int> ans;

        for(int j = x-1; j >= 0 && k > 0; j--)
        {
            if(bucket[j].size() == 0) continue;

            for(int q = 0; q < bucket[j].size() && k > 0; q++)
            {
                ans.push_back(bucket[j][q]);
                k--;
            }
        }

        return ans;
    }
};
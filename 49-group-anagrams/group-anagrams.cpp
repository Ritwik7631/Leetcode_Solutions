class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;

        for(auto a : strs)
        {
            string key = a;

            if(a.empty()) key = "N";

            sort(key.begin(), key.end());
            mp[key].insert(a);
        }

        vector<vector<string>> ans;

        for(auto a : mp)
        {
            vector<string> temp;
            for(auto b : a.second) temp.push_back(b);
            ans.push_back(temp);
        }

        return ans;
    }
};
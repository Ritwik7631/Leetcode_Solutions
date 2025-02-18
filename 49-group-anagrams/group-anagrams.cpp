class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;

        for(auto a : strs)
        {
            string x = a;

            if(x.size() == 0) x = "empty";

            sort(x.begin(), x.end());

            mp[x].push_back(a);
        }

        vector<vector<string>> ans;

        for(auto [x,y] : mp)
        {
            ans.push_back(y);
        }

        return ans;
    }
};
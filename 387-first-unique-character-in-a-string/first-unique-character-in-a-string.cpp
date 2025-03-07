class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> mp;

        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }

        for(auto a : s)
        {
            if(mp[a].size() == 1)
            {
                return mp[a][0];
            }
        }

        return -1;
    }
};
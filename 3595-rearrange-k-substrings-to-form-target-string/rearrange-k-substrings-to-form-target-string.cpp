class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int len = s.size()/k;

        unordered_map<string, int> mp;

        for(int i = 0; i < s.size(); i = i + len)
        {
            mp[s.substr(i, len)]++;
            mp[(t.substr(i, len))]--;
        }

        for(auto a : mp)
        {
            if(a.second != 0) return false;
        }

        return true;
    }
};
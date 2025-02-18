class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> mp;

        for(auto a : s)
        {
            mp[a]++;
        }

        for(auto b : t)
        {
            if(mp[b] == 0) return false;
            mp[b]--;
        }

        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> target;

        for(auto a : s)
        {
            target[a]++;
        }

        for(auto b : t)
        {
            if(target[b] == 0) return false;
            target[b]--;
        }

        return true;
    }
};
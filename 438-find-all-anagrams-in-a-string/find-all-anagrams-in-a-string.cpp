class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        vector<int> target(26);

        for(auto a : p)
        {
            target[a - 'a']++;
        }

        vector<int> window(26);

        for(int i = 0; i < p.size(); i++)
        {
            window[s[i] - 'a']++;
        }

        vector<int> ans;

        int l = 0;
        int r = l + p.size() - 1;

        while(r+1 < s.size())
        {
            if(window == target) ans.push_back(l);

            window[s[l] - 'a']--;
            r++;
            window[s[r] - 'a']++;
            l++;
        }

        if(window == target) ans.push_back(l);

        return ans;
    }
};
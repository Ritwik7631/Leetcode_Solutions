class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};

        vector<int> target(26,0);

        for(auto a: p) target[a - 'a']++;

        vector<int> window(26,0);

        for(int i = 0; i < p.size(); i++)
        {
            window[s[i] - 'a']++;
        }

        vector<int> ans;

        if(window == target) ans.push_back(0);

        int l = 0;

        for(int r = p.size(); r < s.size(); r++)
        {
            if(window[s[l] - 'a'] > 0) window[s[l] - 'a']--;

            l++;
            window[s[r] - 'a']++;

            if(window == target) ans.push_back(l);
        }

        return ans;
    }
};
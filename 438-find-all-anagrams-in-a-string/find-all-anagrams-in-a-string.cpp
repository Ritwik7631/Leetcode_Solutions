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

        for(int r = p.size(); r < s.size(); r++)
        {
            window[s[r]-'a']++;
            window[s[r-p.size()] - 'a']--;

            if(window == target) ans.push_back(r-p.size()+1);
        }

        return ans;
    }
};
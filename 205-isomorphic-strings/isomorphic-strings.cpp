class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        string dupl = s;

        unordered_map<char,char> s_to_t;
        unordered_map<char,char> t_to_s;

        for(int i = 0; i < n; i++)
        {
            s_to_t[s[i]] = t[i];
            t_to_s[t[i]] = s[i];
        }

        string recreate_t = "";

        for(auto a : s)
        {
            recreate_t += s_to_t[a];
        }

        string recreate_s = "";

        for(auto a : t)
        {
            recreate_s += t_to_s[a];
        }

        return recreate_s == s && recreate_t == t;
    }
};
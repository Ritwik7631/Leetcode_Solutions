class Solution {
public:
    bool valid(unordered_map<char, int> &required, unordered_map<char, int> &window)
    {
        for(auto &p : required)
        {
            if(window[p.first] < p.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        int n = s.size();

        unordered_map<char, int> required;
        unordered_map<char, int> window;

        for(auto a : t)
        {
            required[a]++;
        }

        int a = 0;
        int mn = INT_MAX;
        int start = 0;

        int need = required.size();
        int have = 0;

        for(int b = 0; b < n; b++)
        {
            window[s[b]]++;

            if(required.count(s[b]) && window[s[b]] == required[s[b]])
            {
                have++;
            }

            while(have == need)
            {   
                if(b - a + 1 < mn)
                {
                    start = a;
                    mn = b - a + 1;
                }
                window[s[a]]--;

                if(required.count(s[a]) && window[s[a]] < required[s[a]])
                {
                    have--;
                }

                a++;
            }
        }

        if(mn == INT_MAX) return "";
        else
        {
            return s.substr(start, mn);
        }
    }
};

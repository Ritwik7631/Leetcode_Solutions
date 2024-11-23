class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happy = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(j < g.size() && s[i] >= g[j])
            {
                happy++;
                j++;
            }

            if(j == g.size()) break;
        }

        return happy;
    }
};
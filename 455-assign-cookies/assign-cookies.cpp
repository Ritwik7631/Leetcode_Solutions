class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happy = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int n = s.size();
        int m = g.size();
        for(int i = 0; i < n; i++)
        {
            if(j < m && s[i] >= g[j])
            {
                happy++;
                j++;
            }

            if(j == m) break;
        }

        return happy;
    }
};
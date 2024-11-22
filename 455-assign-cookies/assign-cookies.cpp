class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happy = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(j < g.size() && s[i] >= g[j])
            {
                happy++;
                j++;
            }
        }

        return happy;
    }
};
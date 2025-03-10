class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;

        for(auto a : s) mp[a]++;

        set<pair<int,char>> st;

        for(auto a : mp)
        {
            st.insert({a.second, a.first});
        }

        string ans = "";

        while(!st.empty())
        {
            pair<int,char> pr = *st.begin();
            st.erase(st.begin());

            for(int i = 0; i < pr.first; i++)
            {
                ans += pr.second;
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
class Solution {
public:
    int minimumLength(string s) {
        // A : 0 2 3
        // B : 1 5 7 8
        // C : 4 6

        unordered_map<char,int> mp;

        for(auto a : s)
        {
            mp[a]++;
        }
        int ans = 0;
        for(auto a : mp)
        {
            if(a.second % 2 == 0)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }
        }

        return ans;


    }
};
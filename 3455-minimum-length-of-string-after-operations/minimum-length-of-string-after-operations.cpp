class Solution {
public:
    int minimumLength(string s) {
        // A : 0 2 3
        // B : 1 5 7 8
        // C : 4 6

        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }
        int n = s.size();
        int deletions = 0;
        for(auto a : mp)
        {
            int vec = a.second.size();
            int count = 0;
            while(vec >= 3)
            {
                vec -= 2;
                count++;
            }
            deletions += (count*2);
        }

        return n - deletions;


    }
};
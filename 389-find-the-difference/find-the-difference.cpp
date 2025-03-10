class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(auto a : s) mp1[a]++;
        for(auto a : t) mp2[a]++;

        for(auto a : t)
        {
            if(mp2[a]-mp1[a] == 1) return a;
        }

        return 'c';
    }
};
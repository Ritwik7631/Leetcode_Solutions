class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;

        for(auto a : s) ans ^= a;
        for(auto a : t) ans ^= a;

        return ans;
    }
};
class Solution {
public:
    bool isvowel(char x)
    {
        if(x == 'a' || x == 'A' ||
           x == 'e' || x == 'E' ||
           x == 'i' || x == 'I' ||
           x == 'o' || x == 'O' ||
           x == 'u' || x == 'U') return true;

        return false;
    }

    string reverseVowels(string s) {
        vector<pair<int,char>> vow;

        for(int i = 0; i < s.size(); i++)
        {
            if(isvowel(s[i])) vow.push_back({i, s[i]});
        }

        int l = 0;
        int r = vow.size()-1;

        while(l < r)
        {
            pair<int,char> left = vow[l];
            pair<int,char> right = vow[r];

            s[left.first] = right.second;
            s[right.first] = left.second;

            l++;
            r--;
        }

        return s;
    }
};
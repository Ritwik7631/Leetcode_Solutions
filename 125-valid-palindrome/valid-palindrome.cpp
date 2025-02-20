class Solution {
public:
    bool valid(char x)
    {
        x = tolower(x);

        if(int(x) >= int('a') && int(x) <= 'z' || int(x) >= int('0') && int(x) <= '9') return true;

        return false;
    }

    bool isPalindrome(string s) {
        string org = "";

        for(auto a : s)
        {
            if(valid(a))
            {
                org += (char)tolower(a);
            }
        }

        string rev = org;

        reverse(rev.begin(), rev.end());

        return rev == org;
    }
};
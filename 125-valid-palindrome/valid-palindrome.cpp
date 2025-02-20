class Solution {
public:
    bool isPalindrome(string s) {
        string org = "";

        for(auto a : s)
        {
            if(isalnum(a))
            {
                org += (char)tolower(a);
            }
        }

        string rev = org;

        reverse(rev.begin(), rev.end());

        return rev == org;
    }
};
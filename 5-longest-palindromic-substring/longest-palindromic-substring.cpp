class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int ans_length = 0;

        for(int i = 0; i < n; i++)
        {
            
            int l = i;
            int r = i;

            while(l >= 0 && r <= n-1 && s[l] == s[r])
            {
                if(r-l+1 > ans_length)
                {
                    ans_length = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
            
            l = i;
            r = i+1;

            while(l >= 0 && r <= n-1 && s[l] == s[r])
            {
                if(r-l+1 > ans_length)
                {
                    ans_length = r-l+1;
                    ans = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }

        return ans;

    }
};
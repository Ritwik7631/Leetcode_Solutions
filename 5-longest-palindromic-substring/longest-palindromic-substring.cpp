class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int final_length = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int length = j - i + 1;
                bool flag = true;
                
                for(int a = i, b = j; a <= b; a++, b--)
                {
                    if(s[a] != s[b])
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag && length > final_length)
                {
                    final_length = length;
                    ans = s.substr(i, length);
                }
            }
        }

        return ans;
    }
};

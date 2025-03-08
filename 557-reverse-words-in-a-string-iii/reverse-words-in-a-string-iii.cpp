class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        int l = 0;

        for(int r = 0; r < s.size(); r++)
        {
            if(s[r] != ' ')
            {
                temp += s[r];
                continue;
            }
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += " ";
            temp = "";
        }

        reverse(temp.begin(), temp.end());
        ans += temp;

        return ans;

    }

    // 0 1 2 3 4 5__
};
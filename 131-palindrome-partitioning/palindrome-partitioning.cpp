class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string x)
    {
        int n = x.size();
        for(int i = 0; i < n/2; i++)
        {
            if(x[i] != x[n-1-i]) return false;
        }

        return true;
    }

    void fn(int i, string s, vector<string>& curr)
    {
        if(i == s.size())
        {
            ans.push_back(curr);
            return;
        }

        string temp = "";

        for(int j = i; j < s.size(); j++)
        {
            temp += s[j];

            if(isPalindrome(temp))
            {
                curr.push_back(temp);
                fn(j+1, s, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<string> curr;

        fn(0, s, curr);

        return ans;
    }
};
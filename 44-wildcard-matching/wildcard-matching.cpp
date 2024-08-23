class Solution {
public:
    bool fn(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(j == p.size())
        {
            return i == s.size();
        }

        if(i == s.size())
        {
            return p[j] == '*' && fn(i, j+1, s, p, dp);
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = fn(i+1, j+1, s, p, dp);
        }
        else if(p[j] == '*') return dp[i][j] = fn(i, j+1, s, p, dp) || fn(i+1, j, s, p, dp);
        else return dp[i][j] = false;
    
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        return fn(0,0,s,p,dp);
    }
};
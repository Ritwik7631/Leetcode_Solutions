class Solution {
public:
    bool fn(int i, int j, string &p, string &s, vector<vector<int>>& dp) {
        // Base cases
        if(i < 0 && j < 0) return true;         // Both pattern and string are exhausted.
        if(i < 0 && j >= 0) return false;        // Pattern is empty but string is not.
        if(j < 0) {                            // String is empty.
            // The remaining pattern must form valid "x*" pairs to match an empty string.
            if(i > 0 && p[i] == '*')
                return fn(i - 2, j, p, s, dp);
            return false;
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        // Direct match or '.' wildcard.
        if(p[i] == s[j] || p[i] == '.')
            return dp[i][j] = fn(i - 1, j - 1, p, s, dp);
        
        // Handling '*' operator.
        if(p[i] == '*')
            return dp[i][j] = fn(i - 2, j, p, s, dp) ||
                ((p[i - 1] == s[j] || p[i - 1] == '.') && fn(i, j - 1, p, s, dp));
        
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return fn(n-1, m-1, p, s, dp);
    }
};
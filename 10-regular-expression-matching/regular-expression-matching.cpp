class Solution {
public:
    // the function returns whether we have a complete match from 0 to i with pattern 0 to j
    bool fn(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i < 0)
        {
            if(j < 0) return true;

            if(p[j] == '*')
            {
                return fn(i, j-2, s, p, dp);
            }

            return false;
        }

        if(j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(p[j] == '.')
        {
            return dp[i][j] = fn(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*')
        {
            char prec = p[j-1];

            bool ignore = fn(i, j-2, s, p, dp);

            if(prec == s[i] || prec == '.')
            {
                bool match_move = fn(i-1, j-2, s, p, dp);
                bool match_stay = fn(i-1, j, s, p, dp); 

                ignore = ignore || match_move || match_stay;
            }

            return dp[i][j] = ignore;
        }
        else if(s[i] == p[j])
        {
            return dp[i][j] = fn(i-1, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return fn(n-1, m-1, s, p, dp);
    }
};
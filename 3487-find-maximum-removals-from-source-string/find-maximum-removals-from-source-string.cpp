class Solution {
public:
    int fn(int i, int j, int k, string &source, string &pattern, vector<int> &ti, vector<vector<int>> &dp)
    {
        if(j < 0) return k + 1;
    
        if(i < 0) return INT_MIN;

        if(dp[i][j] != -1) return dp[i][j];

        int match = INT_MIN;
        int notmatch = INT_MIN;
        
        if(source[i] == pattern[j])
        {
            if(k >= 0 && i == ti[k])
            {
                notmatch = fn(i-1, j, k-1, source, pattern, ti, dp) + 1;
                match = fn(i-1, j-1, k-1, source, pattern, ti, dp);
                return dp[i][j] = max(notmatch, match);
            }
            else
            {
                match = fn(i-1, j-1, k, source, pattern, ti, dp);
                notmatch = fn(i-1, j, k, source, pattern, ti, dp);
                return dp[i][j] = max(match, notmatch);
            }
        }
        else
        {
            if(k >= 0 && i == ti[k])
            {
                notmatch = fn(i-1, j, k-1, source, pattern, ti,dp) + 1;
                return dp[i][j] = max(notmatch, match);
            }
            else
            {
                notmatch = fn(i-1, j, k, source, pattern, ti,dp);
                return dp[i][j] = max(notmatch, match);
            }
        }
        
        return INT_MIN;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        int m = pattern.size();
        int k = targetIndices.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        return fn(n-1,m-1, k-1, source, pattern, targetIndices, dp);
    }
};
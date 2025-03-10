class Solution {
public:
    int fn(int i, int j, string& word1, string& word2, vector<vector<int>>& dp)
    {
        if(j < 0)
        {
            return i+1; // we have to delete everything in word1 to convert
        }

        if(i < 0)
        {
            // if word1 is completely processed but there are still some letters left in word2
            // the only thing to do here is to keep inserting
            return j+1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int a = 0;
        // insert
        a = 1 + fn(i, j-1, word1, word2, dp);
        
        int b = 0;
        // delete
        b = 1 + fn(i-1, j, word1, word2, dp);

        int c = 0;
        // replace
        c = 1 + fn(i-1,j-1,word1,word2, dp);

        int d = INT_MAX;
        // do nothing
        if(word1[i] == word2[j]) d = 0 + fn(i-1,j-1,word1, word2, dp);

        return dp[i][j]=min({a,b,c,d});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return fn(n-1, m-1, word1, word2,dp);
    }
};
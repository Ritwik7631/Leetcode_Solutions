class Solution {
public:
    // int fn(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    // {
    //     if(j - i == 1)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans = INT_MAX;

    //     for(int x = i+1; x < j; x++)
    //     {
    //         int range1 = fn(i, x, cuts, dp);
    //         int range2 = fn(x, j, cuts, dp);

    //         int cost = (cuts[j]-cuts[i]) + range1 + range2;

    //         ans = min(ans, cost);
    //     }

    //     return dp[i][j] = ans;
    // }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(cuts.size() + 1, vector<int> (cuts.size() + 1, 0));

        for(int i = cuts.size()-2; i >= 0; i--)
        {
            for(int j = i+2; j <= cuts.size()-1; j++)
            {
                int ans = INT_MAX;

                for(int x = i+1; x < j; x++)
                {
                    int range1 = dp[i][x];
                    int range2 = dp[x][j];

                    int cost = (cuts[j]-cuts[i]) + range1 + range2;

                    ans = min(ans, cost);

                    dp[i][j] = ans;
                }

            }
        }

        return dp[0][cuts.size()-1];
    }

    /*
    
    cuts = 0, 1, 3, 4, 5, 7 n = 7
    
    fn(0,5)
      -> fn(0,1) fn(1, 5) || fn(0, 2) fn(2, 5) || 
         -> base -> fn(1,2) fn(2,5) || fn(1,3) fn(3,5)
                   -> base  -> fn(2,3) fn(3, 5) || fn(2,4) fn(4,5)
                             -> base  -> fn(3,4) fn(4,5)


    */


};
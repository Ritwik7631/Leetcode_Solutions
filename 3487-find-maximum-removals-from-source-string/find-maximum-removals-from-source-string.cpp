class Solution {
public:
    int fn(int sindex, int pindex, int s, int p, const vector<bool> &f, 
           const string &source, const string &pattern, vector<vector<int>> &memo)
    {
        // Base Case 1: Reached end of source
        if(sindex == s)
        {
            if(pindex == p)
                return 0;
            else
                return INT_MIN;
        }

        // Base Case 2: Entire pattern has been matched
        if(pindex == p)
        {
            if(f[sindex])
            {
                int res = fn(sindex + 1, pindex, s, p, f, source, pattern, memo);
                if(res != INT_MIN)
                    return 1 + res;
                else
                    return INT_MIN;
            }
            else
            {
                return fn(sindex + 1, pindex, s, p, f, source, pattern, memo);
            }
        }

        // Check if result is already computed
        if(memo[sindex][pindex] != -1)
            return memo[sindex][pindex];

        int best = INT_MIN;

        // Option 1: Take the current character for the pattern if it matches
        if(source[sindex] == pattern[pindex])
        {
            int res = fn(sindex + 1, pindex + 1, s, p, f, source, pattern, memo);
            if(res != INT_MIN)
                best = max(best, res);
        }

        // Option 2: Remove the current character if it's removable
        if(f[sindex])
        {
            int res = fn(sindex + 1, pindex, s, p, f, source, pattern, memo);
            if(res != INT_MIN)
                best = max(best, 1 + res);
        }

        // Option 3: Skip the current character without removing
        int res = fn(sindex + 1, pindex, s, p, f, source, pattern, memo);
        if(res != INT_MIN)
            best = max(best, res);

        // Memoize the result
        memo[sindex][pindex] = best;

        return best;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int s = source.size();
        int p = pattern.size();

        // Convert targetIndices to a vector<bool> for O(1) lookups
        vector<bool> f(s, false);
        for(auto index : targetIndices){
            if(index >= 0 && index < s){
                f[index] = true;
            }
        }

        // Initialize memoization table with -1
        // Dimensions: s x p
        // Note: If p is 0, no characters need to be matched
        // If s is 0, and p is not 0, it's impossible
        // Initialize with -1 indicating uncomputed states
        vector<vector<int>> memo(s, vector<int>(p, -1));

        // Start recursion from sindex = 0 and pindex = 0
        int result = fn(0, 0, s, p, f, source, pattern, memo);

        // If result is negative, it means it's impossible to match the pattern
        if(result == INT_MIN)
            return 0;
        else
            return result;
    }
};

// class Solution {
// public:
//     bool fx(int i, string &source, string &pattern, vector<int>& ti)
//     {
//         char original = source[ti[i]];
//         source[ti[i]] = 'X';

//         int n = source.size();
//         int m = pattern.size();

//         int x = 0;
//         int y = 0;

//         while(x < n && y < m)
//         {
//             if(source[x] == pattern[y])
//             {
//                 y++;
//             }

//             x++;
//         }

//         // cout << source << " " << pattern << endl;

//         // if(y == m) cout << "pattern match" << endl;
//         // else cout << "no match" << endl;

//         source[ti[i]] = original;
        
//         return y == m;
//     }

//     int fn(int i, string &source, string &pattern, vector<int>& ti, vector<int> &dp)
//     {
//         if(i < 0) return 0;

//         if(dp[i] != -1) return dp[i];
//         int pick = INT_MIN;
//         int notpick = INT_MIN;

//         notpick = fn(i-1, source, pattern, ti, dp);

//         if(fx(i, source, pattern, ti) == true)
//         {
//             char original = source[ti[i]];
//             source[ti[i]] = 'X';
//             pick = 1 + fn(i-1, source, pattern, ti, dp);
//             source[ti[i]] = original;
//         }

//         return dp[i] = max(pick, notpick);
//     }

//     int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
//         int n = targetIndices.size();

//         vector<int> dp(n+1, -1);

//         return fn(n-1, source, pattern, targetIndices, dp);
//     }
// };




// --------------------------------------------------------------------------------
// class Solution {
// public:
//     int fn(int i, string source, string pattern, vector<int>& targetIndices)
//     {
//         bool flag = false;

//         char original = source[i];

//         source[i] = 'Z';

//         flag = fx(pattern, source);

//         int ans = 0;

//         if(flag)
//         {
//             targetIndices[i] = -1;
//             for(int j = 0; j < targetIndices.size(); j++)
//             {
//                 int operations = 0;
//                 if(targetIndices[j] != -1)
//                 {
//                     operations += 1;
//                     operations += fn(j, source, pattern, targetIndices);
//                 }
//                 ans = max(ans, operations);
//             }
//         }
//         else
//         {
               
//         }

//         source[i] = original;
//     }

//     int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
//        int count = INT_MIN;

//        for(int i = 0; i < targetIndices.size(); i++)
//        {
//             vector<int> temp = targetIndices;
//             count = max(count, fn(targetIndices[i], source, pattern, temp));
//        } 
//     }
// };
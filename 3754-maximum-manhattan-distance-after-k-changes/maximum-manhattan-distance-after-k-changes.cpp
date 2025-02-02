class Solution {
public:
    int fn(unordered_map<char,int> &mp, int k)
    {
        int res = 0;
        {
            int mn = min(mp['N'], mp['S']);
            int mx = max(mp['N'], mp['S']);

            int del = min(k, mn);

            res += (mx-mn) + 2*del;
            k -= del;
        }
        {
            int mn = min(mp['E'], mp['W']);
            int mx = max(mp['E'], mp['W']);

            int del = min(k, mn);

            res += (mx-mn) + 2*del;
            k -= del; 
        }

        return res;
    }

    int maxDistance(string s, int k) {
        unordered_map<char,int> freq;

        int n = s.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            freq[s[i]]++;
            ans = max(ans, fn(freq, k));
        }

        return ans;
    }
};
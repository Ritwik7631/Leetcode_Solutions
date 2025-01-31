#define ll long long
class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        ll res1 = 0;

        int n = arr.size();

        for(int i = 0; i < n; i++)
        {
            res1 += abs(brr[i]-arr[i]);
        }

        ll res2 = k;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for(int i = 0; i < n; i++)
        {
            res2 += abs(brr[i]-arr[i]);
        }

        return min(res1,res2);
    }
};
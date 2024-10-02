class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int mn = INT_MAX;
        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            mx = max(mx, prices[i] - mn);
            mn = min(mn, prices[i]);
        }

        return mx;
    }
};
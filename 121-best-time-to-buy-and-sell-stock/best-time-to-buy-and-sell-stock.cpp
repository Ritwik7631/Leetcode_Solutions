class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int n = prices.size();

        vector<int> maxright(n);

        maxright[n-1] = prices[n-1];

        for(int i = n-2; i >= 0; i--)
        {
            maxright[i] = max(maxright[i+1], prices[i]);
        }

        // for(auto a : maxright) cout << a << " ";
        // cout << endl;

        for(int i = 0; i < n; i++)
        {
            ans = max(ans, maxright[i] - prices[i]);
        }

        return ans;
    }
};
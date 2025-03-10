class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;

        int mn = INT_MAX;
        for(auto a : prices)
        {
            mn = min(mn, a);

            ans = max(ans, a - mn);
        }

        return ans;
    }
};
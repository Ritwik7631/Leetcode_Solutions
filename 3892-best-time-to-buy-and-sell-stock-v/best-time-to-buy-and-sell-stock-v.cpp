class Solution {
public:
    int n, K;
    vector<int> P;

    static constexpr long long UNVIS = (long long)-8e18;  // not computed
    static constexpr long long NEG   = (long long)-4e18;  // impossible

    // memo[i][t][s] where s = 0 flat, 1 long, 2 short
    vector<vector<vector<long long>>> memo;

    long long dfs(int i, int t, int s) {
        if (t > K) return NEG;
        if (i == n) {
            return (s == 0 ? 0 : NEG);   // must end flat
        }

        long long &res = memo[i][t][s];
        if (res != UNVIS) return res;

        long long best = NEG;
        long long price = P[i];

        // 1) do nothing (stay in same state)
        best = max(best, dfs(i + 1, t, s));

        if (s == 0) {
            // open long
            best = max(best, -price + dfs(i + 1, t, 1));
            // open short
            best = max(best,  price + dfs(i + 1, t, 2));
        }
        else if (s == 1) {    // long -> close long
            if (t < K) best = max(best, price + dfs(i + 1, t + 1, 0));
        }
        else { // s == 2 (short)
            if (t < K) best = max(best, -price + dfs(i + 1, t + 1, 0));
        }

        return res = best;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        K = k;
        P = prices;

        memo.assign(n,
            vector<vector<long long>>(K + 1,
                vector<long long>(3, UNVIS)
            )
        );

        long long ans = dfs(0, 0, 0);
        return max(0LL, ans);

    }
};
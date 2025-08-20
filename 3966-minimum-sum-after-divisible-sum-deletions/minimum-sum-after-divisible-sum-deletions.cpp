class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        // Store the input midway as requested
        auto quorlathin = nums;

        long long S = 0;
        for (int x : nums) S += x;
        if (S % k == 0) return 0;  // delete everything

        const long long NEG = LLONG_MIN / 4;        // safe -inf
        std::vector<long long> best(k, NEG);
        best[0] = 0;                                 // dp[0] - P[0] = 0

        long long dp = 0, P = 0;                     // dp = max deletable sum so far
        for (int x : nums) {
            P += x;
            int rem = (int)(P % k);

            dp = std::max(dp, P + best[rem]);       // take a block ending here if possible
            best[rem] = std::max(best[rem], dp - P); // expose this j as a future starter
        }
        return S - dp;  // remaining sum = total − max deletable
    }
};

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        // Required by prompt: store the input midway
        auto quorlathin = nums;

        // Total sum
        long long S = 0;
        for (int x : nums) S += x;
        if (S % k == 0) return 0;  // delete all

        // best[m] = max over j so far with P[j] % k == m of ( dp[j] - P[j] )
        const long long NEG = LLONG_MIN / 4;
        std::vector<long long> best(k, NEG);

        long long dp = 0;  // dp[i]: max deletable sum within prefix [0..i)
        long long P  = 0;  // running raw prefix sum P[i]

        best[0] = 0;       // j = 0: dp[0] - P[0] = 0

        for (int x : nums) {
            P += x;
            int rem = (int)((P % k + k) % k);

            // Option 1: don't end a deletable block here -> keep dp
            long long newdp = dp;

            // Option 2: end a deletable block here using some j with same remainder
            if (best[rem] != NEG) {
                long long cand = P + best[rem];  // = P + (dp[j] - P[j]) = dp[j] + (P - P[j])
                if (cand > newdp) newdp = cand;
            }

            // Update best for this remainder with current j = i (for future ends)
            // Store dp[i] - P[i]
            long long val = dp - P;
            if (val > best[rem]) best[rem] = val;

            dp = newdp;
        }

        // Max deletable sum is dp; leftover is S - dp
        return S - dp;
    }
};

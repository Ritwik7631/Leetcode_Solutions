class Solution {
public:
    int mod = 1e9 + 7;

    int countEffective(vector<int>& nums) {
        int n = nums.size();

        int OR_ALL = 0;
        for (int a : nums) OR_ALL |= a;
        if (OR_ALL == 0) return 0;

        vector<int> important_bits;
        for (int i = 0; i < 20; i++) {
            if (OR_ALL & (1 << i)) important_bits.push_back(i);
        }

        int K = important_bits.size();
        int m = 1 << K;

        // freq[mask] = how many numbers have EXACT compressed mask = mask
        vector<int> freq(m, 0);
        for (int x : nums) {
            int mask = 0;
            for (int b = 0; b < K; b++) {
                if (x & (1 << important_bits[b])) {
                    mask |= (1 << b);
                }
            }
            freq[mask]++;
        }

        // F[mask] will store sum over all submasks S ⊆ mask of freq[S]
        vector<long long> F(m);
        for (int mask = 0; mask < m; mask++) F[mask] = freq[mask];

        // iterative SOS DP: submask sums
        for (int bit = 0; bit < K; bit++) {
            for (int mask = 0; mask < m; mask++) {
                if (mask & (1 << bit)) {
                    F[mask] += F[mask ^ (1 << bit)];
                }
            }
        }
        // now F[mask] = Σ freq[S] for all S ⊆ mask

        // precompute powers of 2 up to n (max possible "good" count)
        vector<long long> pow2(n + 1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        long long ans = 0;

        // inclusion–exclusion over all nonempty X
        for (int X = 1; X < m; X++) {
            int comp = (m - 1) ^ X;        // complement in K-bit space
            long long good = F[comp];      // numbers avoiding all bits in X

            long long ways = pow2[good];   // subsequences that kill X

            if (__builtin_popcount(X) & 1) {
                ans = (ans + ways) % mod;        // odd → add
            } else {
                ans = (ans - ways + mod) % mod;  // even → subtract
            }
        }

        return (int)ans;
    }
};

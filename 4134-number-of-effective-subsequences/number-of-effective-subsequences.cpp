class Solution {
public:
    static constexpr int MOD = 1000000007;

    int countEffective(vector<int>& nums) {
        int n = (int)nums.size();
        long long G = 0;
        for (int x : nums) G |= x;

        // If global OR is 0, no bit can ever be "lost" → no effective subsequence
        if (G == 0) return 0;

        // Compress the set bits of G into [0..m-1]
        int bitId[20];
        for (int i = 0; i < 20; ++i) bitId[i] = -1;
        int m = 0;
        for (int b = 0; b < 20; ++b) {
            if ((G >> b) & 1) {
                bitId[b] = m++;
            }
        }

        int maskCount = 1 << m;

        // freq[mask] = how many nums[i] have exactly this bit pattern (over the m relevant bits)
        vector<long long> freq(maskCount, 0);
        for (int x : nums) {
            int mask = 0;
            for (int b = 0; b < 20; ++b) {
                if (bitId[b] != -1 && ((x >> b) & 1)) {
                    mask |= (1 << bitId[b]);
                }
            }
            freq[mask]++;
        }

        // SOS DP: subCount[mask] = sum_{sub ⊆ mask} freq[sub]
        // Interpreted as: number of indices whose bitmask is a subset of "mask".
        vector<long long> subCount = freq;
        for (int i = 0; i < m; ++i) {
            for (int mask = 0; mask < maskCount; ++mask) {
                if (mask & (1 << i)) {
                    subCount[mask] += subCount[mask ^ (1 << i)];
                }
            }
        }

        // Precompute powers of 2 up to n
        vector<long long> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int fullMask = maskCount - 1;
        long long ans = 0;

        // Inclusion–exclusion over non-empty subsets of bits T
        // For each T:
        //   let U_T be union of index-sets for bits in T
        //   |U_T| = n - (#indices whose bitmask has no bit from T)
        //         = n - subCount[complement_of_T]
        //   subsequences that cover all of U_T = 2^(n - |U_T|)
        //   contribution sign = (-1)^(|T|-1)
        for (int T = 1; T < maskCount; ++T) {
            int bits = __builtin_popcount(T);
            int complement = fullMask ^ T;

            long long noBitCount = subCount[complement]; // indices with no bit from T
            long long unionSize = n - noBitCount;

            if (unionSize == 0) continue; // impossible to cover any bit in T

            long long ways = pow2[n - (int)unionSize];
            if (bits & 1) {
                ans += ways;
                if (ans >= MOD) ans -= MOD;
            } else {
                ans -= ways;
                if (ans < 0) ans += MOD;
            }
        }

        return (int)ans;
    }
};

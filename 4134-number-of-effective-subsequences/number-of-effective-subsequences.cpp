class Solution {
public:
    static const int MOD = 1'000'000'007;

    int countEffective(vector<int>& nums) {
        int n = nums.size();

        // 1. Compute full OR and find number of bits K
        int OR_all = 0;
        for (int x : nums) OR_all |= x;

        // Compress to only relevant bits
        // Let K = number of bits needed for OR_all
        vector<int> bits;
        for (int b = 0; b < 20; b++)
            if (OR_all & (1 << b))
                bits.push_back(b);

        int K = bits.size();              // # of relevant bits
        int M = 1 << K;                   // masks: 0..(2^K - 1)

        // 2. Build freq[mask] where mask is in "compressed K-bit space"
        vector<int> freq(M, 0);

        for (int x : nums) {
            int cmask = 0;
            for (int i = 0; i < K; i++) {
                if (x & (1 << bits[i])) 
                    cmask |= (1 << i);
            }
            freq[cmask]++;
        }

        // 3. SOS DP (submask sum): F[mask] = sum(freq[sub]) over all sub ⊆ mask
        vector<int> F = freq;
        for (int bit = 0; bit < K; bit++) {
            for (int mask = 0; mask < M; mask++) {
                if (mask & (1 << bit)) {
                    F[mask] = (F[mask] + F[mask ^ (1 << bit)]) % MOD;
                }
            }
        }

        // F[mask] = # of numbers whose compressed bitmask ⊆ mask.

        // 4. Inclusion-Exclusion over all non-empty X ⊆ OR_all_bits
        long long ans = 0;

        for (int X = 1; X < M; X++) {
            // Numbers that DO NOT intersect X are exactly those
            // whose mask ⊆ (~X) in K-bit space.
            int complement = ((M - 1) ^ X); // invert only K bits

            long long good = F[complement];  // numbers avoiding X
            long long bad = n - good;        // numbers hitting at least one bit in X

            // subsequences of removals must include ALL bad elements
            // and may include any subset of the remaining good ones
            long long ways = modpow(2, good); // choose any subset of "good" to include in removal

            if (__builtin_popcount(X) % 2 == 1)
                ans = (ans + ways) % MOD;
            else
                ans = (ans - ways + MOD) % MOD;
        }

        return ans;
    }

    long long modpow(long long a, long long e) {
        long long r = 1;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }
};

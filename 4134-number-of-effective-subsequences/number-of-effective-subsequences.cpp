class Solution {
public:
    int mod = 1e9+7;
    int K;

    int countEffective(vector<int>& nums) {
        int n = nums.size();

        int OR_ALL = 0;
        for(int a : nums) OR_ALL |= a;

        if(OR_ALL == 0) return 0;

        vector<int> important_bits;

        for(int i = 0; i < 20; i++){
            if(OR_ALL & (1 << i)) important_bits.push_back(i);
        }

        K = important_bits.size(); // how many bits are turned on in OR_ALL
        int m = 1 << K; // submasks of K
        
        vector<long long> freq(m,0);

        for(int i = 0; i < n; i++){
            int mask = 0;
            for(int b = 0; b < K; b++){
                if(nums[i] & (1 << important_bits[b])) mask |= (1 << b);
            }
            freq[mask]++;
        }

        vector<long long> F(m);

        for(int i = 0; i < m; i++) F[i] = freq[i];

        for(int bit = 0; bit < K; bit++){
            for(int mask = 0; mask < m; mask++){
                if(mask & (1 << bit)){
                    F[mask] += F[mask ^ (1 << bit)];
                }
            }
        }

        vector<long long> pow2(n+1);
        pow2[0] = 1;
        for(int i = 1; i <= n; i++){
            pow2[i] = (pow2[i-1] * 2) % mod;
        }

        long long ans = 0;

        for(int X = 1; X < m; X++){
            int comp = (m-1) ^ X;
            long long good = F[comp];

            long long ways = pow2[good];

            if(__builtin_popcount(X) & 1){
                ans = (ans + ways) % mod;
            }
            else{
                ans = (ans - ways + mod) % mod;
            }
        }

        return (int)ans;
        
    }
};
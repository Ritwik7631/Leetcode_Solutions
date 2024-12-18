class Solution {
public:
    int mod = 1e9+7;
    vector<long long> prefixHash; // hash[i] return hash from 0 to i
    vector<long long> powerBase; // powers of the (base^i)%mod

    void computeHashes(vector<int>& nums) {
        int n = nums.size();
        prefixHash.resize(n + 1, 0);
        powerBase.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            powerBase[i] = (powerBase[i-1] * 51) % mod;
        }

        for (int i = 0; i < n; i++) {
            prefixHash[i+1] = (prefixHash[i] * 51 + nums[i]) % mod;
        }
    }

    int hash(int start, int len) {
        return (prefixHash[start+len] - (prefixHash[start] * powerBase[len]) % mod + mod) % mod;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        computeHashes(nums);
        int count = 0;

        for (int i = 1; i <= n-2; i++) {   
            for (int j = i+1; j <= n-1; j++) {
                bool cond1 = false, cond2 = false;

                // Condition 1: nums1 is a prefix of nums2
                if (j - i >= i - 0) {
                    int h1 = hash(0, i); // nums1
                    int h2 = hash(i, i); // nums2 of length nums1
                    if (h1 == h2) cond1 = true;
                }

                // Condition 2: nums2 is a prefix of nums3
                if (n - j >= j - i) {
                    int h3 = hash(i, j - i); // nums2
                    int h4 = hash(j, j - i); // nums3 of length nums2
                    if (h3 == h4) cond2 = true;
                }

                if (cond1 || cond2) count++;
            }
        }

        return count;
    }
};

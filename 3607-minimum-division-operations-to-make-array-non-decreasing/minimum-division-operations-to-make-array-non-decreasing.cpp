class Solution {
public:
    vector<int> gpd; // greatest proper divisor

    void precomputeGPD(int N) {
        gpd.resize(N + 1);
        vector<int> spf(N + 1); // Smallest prime factor

        for (int i = 0; i <= N; ++i) {
            spf[i] = i;
        }

        for (int x = 2; x * x <= N; ++x) {
            if (spf[x] == x) { // x is prime
                for (int m = x * x; m <= N; m += x) {
                    if (spf[m] == m) {
                        spf[m] = x;
                    }
                }
            }
        }

        for (int x = 2; x <= N; ++x) {
            if (x == spf[x]) {
                // x is prime, so its greatest proper divisor is 1
                gpd[x] = 1;
            } else {
                gpd[x] = x / spf[x];
            }
        }
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        precomputeGPD(maxNum); // Precompute up to the maximum number in nums

        int count = 0;

        for (int i = n - 2; i >= 0; --i) {
            // Need to reduce nums[i] to be <= nums[i + 1]
            while (nums[i] > nums[i + 1]) {
                // If greatest proper divisor is 1, cannot reduce further
                if (gpd[nums[i]] == 1) return -1;

                // Divide nums[i] by its greatest proper divisor
                nums[i] /= gpd[nums[i]];
                ++count;
            }
        }
        return count;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    const int base = 51; // Base should be greater than the maximum possible nums[i]

    vector<long long> prefixHash;
    vector<long long> powerBase;

    // Function to precompute prefix hashes and power bases
    void computeHash(const vector<int>& nums){
        int n = nums.size();
        prefixHash.resize(n + 1, 0);
        powerBase.resize(n + 1, 1);
        for(int i = 0; i < n; i++){
            prefixHash[i + 1] = (prefixHash[i] * base + nums[i]) % mod;
            powerBase[i + 1] = (powerBase[i] * base) % mod;
        }
    }

    // Function to get the hash of subarray [start, start + len)
    long long getHash(int start, int len){
        return (prefixHash[start + len] - (prefixHash[start] * powerBase[len]) % mod + mod) % mod;
    }

    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        computeHash(nums);
        int count = 0;

        // Iterate through all possible split points
        for(int i = 1; i <= n - 2; i++) { // Split after index i-1 for nums1
            for(int j = i + 1; j <= n - 1; j++) { // Split after index j-1 for nums2
                bool cond1 = false, cond2 = false;

                // Condition 1: nums1 is a prefix of nums2
                if(j - i >= i){
                    long long h1 = getHash(0, i);      // Hash of nums1
                    long long h2 = getHash(i, i);      // Hash of the first i elements of nums2
                    if(h1 == h2){
                        cond1 = true;
                    }
                }

                // Condition 2: nums2 is a prefix of nums3
                if(n - j >= j - i){
                    long long h3 = getHash(i, j - i);  // Hash of nums2
                    long long h4 = getHash(j, j - i);  // Hash of the first (j-i) elements of nums3
                    if(h3 == h4){
                        cond2 = true;
                    }
                }

                if(cond1 || cond2){
                    count++;
                }
            }
        }
        return count;
    }
};

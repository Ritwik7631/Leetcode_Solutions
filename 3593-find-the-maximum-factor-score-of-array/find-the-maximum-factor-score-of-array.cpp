#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Using unsigned long long to handle larger numbers
    typedef unsigned long long ull;

    ull gcd(ull a, ull b) {
        while (b != 0) {
            ull temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ull lcm(ull a, ull b) {
        // To prevent overflow, divide before multiplication
        return a / gcd(a, b) * b;
    }

    ull gcd_array(const vector<int>& nums, int excludeIndex) {
        ull result = 0;
        bool initialized = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == excludeIndex) continue;
            if (!initialized) {
                result = nums[i];
                initialized = true;
            } else {
                result = gcd(result, nums[i]);
            }
        }
        return initialized ? result : 0;
    }

    ull lcm_array(const vector<int>& nums, int excludeIndex) {
        ull result = 0;
        bool initialized = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == excludeIndex) continue;
            if (!initialized) {
                result = nums[i];
                initialized = true;
            } else {
                ull gcd_val = gcd(result, nums[i]);
                // Check for possible division by zero
                if (gcd_val == 0) return 0;
                // To prevent overflow
                result = result / gcd_val * nums[i];
            }
        }
        return initialized ? result : 0;
    }

    long long maxScore(vector<int>& nums) {
        ull max_factor_score = 0;
        int n = nums.size();

        for (int k = -1; k < n; ++k) {
            ull current_gcd = gcd_array(nums, k);
            ull current_lcm = lcm_array(nums, k);

            // If either GCD or LCM is zero, skip
            if (current_gcd == 0 || current_lcm == 0) continue;

            ull factor_score = current_gcd * current_lcm;
            max_factor_score = max(max_factor_score, factor_score);
        }

        return max_factor_score;
    }
};

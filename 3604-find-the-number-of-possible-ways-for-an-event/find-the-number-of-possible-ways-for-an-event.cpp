#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    // Function to precompute Stirling numbers
    vector<vector<long long>> precompute_stirling(int n_max) {
        vector<vector<long long>> stirling(n_max + 1, vector<long long>(n_max + 1, 0));
        stirling[0][0] = 1;  // Base case
        
        for (int n = 1; n <= n_max; n++) {
            for (int k = 1; k <= n; k++) {
                stirling[n][k] = (stirling[n-1][k-1] + (k * stirling[n-1][k]) % MOD) % MOD;
            }
        }
        
        return stirling;
    }

    // Function to compute permutations P(x, k)
    long long permutations(int x, int k) {
        long long result = 1;
        for (int i = 0; i < k; i++) {
            result = (result * (x - i)) % MOD;
        }
        return result;
    }

    // Function to compute y^k mod (MOD) using binary exponentiation
    long long mod_pow(int y, int k) {
        long long result = 1;
        long long base = y;

        while (k > 0) {
            if (k % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            k /= 2;
        }
        return result;
    }

    // Main function to calculate the number of ways for the event
    int numberOfWays(int n, int x, int y) {
        vector<vector<long long>> stirling = precompute_stirling(1000);
        
        long long result = 0;
        for (int k = 1; k <= min(n, x); k++) {
            long long stage_perm = permutations(x, k);        // P(x, k)
            long long stirling_val = stirling[n][k];          // S(n, k)
            long long score_power = mod_pow(y, k);            // y^k
            
            // Add up the result for each k
            result = (result + stage_perm * stirling_val % MOD * score_power % MOD) % MOD;
        }
        
        return static_cast<int>(result);  // Return result as int, modulo applied
    }
};

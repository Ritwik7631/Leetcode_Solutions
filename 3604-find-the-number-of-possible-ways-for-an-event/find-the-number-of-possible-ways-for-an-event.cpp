#include <vector>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;  

    vector<vector<int>> fn_sterling(int n) {
        vector<vector<int>> sterling(n + 1, vector<int>(n + 1, 0));
        sterling[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                sterling[i][k] = (sterling[i - 1][k - 1] + (1LL * k * sterling[i - 1][k]) % mod) % mod;
            }
        }

        return sterling;
    }

    int permutations(int n, int k) {
        long long result = 1;
        for (int i = n - k + 1; i <= n; i++) {
            result = (result * i) % mod;
        }
        return result;
    }

    int power(int y, int k) {
        long long result = 1;
        long long base = y;

        while (k > 0) {
            if (k % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            k /= 2;
        }
        return result;
    }

    int numberOfWays(int n, int x, int y) {
        long long count = 0;

        vector<vector<int>> sterling_arr = fn_sterling(1000);

        for (int k = 1; k <= min(n, x); k++) {
            long long perm = permutations(x, k);  
            long long points = power(y, k);       
            long long sterling = sterling_arr[n][k];  

            // Sum up the result and apply modulo at every step
            count = (count + perm * points % mod * sterling % mod) % mod;
        }

        return count;
    }
};

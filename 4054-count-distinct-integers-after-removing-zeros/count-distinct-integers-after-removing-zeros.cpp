#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countDistinct(long long n) {
        string s = to_string(n);
        int k = (int)s.size();

        // precompute powers of 9
        long long pow9[20];
        pow9[0] = 1;
        for (int i = 1; i < 20; ++i) {
            pow9[i] = pow9[i - 1] * 9;
        }

        long long ans = 0;

        // 1) numbers with fewer digits than n
        for (int L = 1; L < k; ++L) {
            ans += pow9[L];      // 9^L numbers with no zero digit
        }

        // 2) numbers with same number of digits as n
        bool hasZero = false;
        for (int i = 0; i < k; ++i) {
            int d = s[i] - '0';
            int remaining = k - i - 1;

            if (d == 0) {
                hasZero = true;
                break;
            }

            // digits 1..(d-1) at this position, then any non-zero digits for the rest
            ans += (long long)(d - 1) * pow9[remaining];
        }

        // if n itself has no zero digit, count it
        if (!hasZero) ans += 1;

        return ans;
    }
};

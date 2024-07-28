#include <cmath>
#include <iostream>

class Solution {
public:
    bool isPrime(int x) {
        if (x <= 1) {
            return false;
        }
        if (x == 2) {
            return true;
        }
        if (x % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= std::sqrt(x); i += 2) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                ++count;
            }
        }
        return count;
    }

    int nonSpecialCount(int l, int r) {
        // x is special <=> x = p^2 for some prime p
        return (r - l + 1) - countPrimes(std::sqrt(r) + 1) + countPrimes(std::sqrt(l - 1) + 1);
    }
};
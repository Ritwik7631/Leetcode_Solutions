#include <cmath>
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> sieve(int maxN) {
        std::vector<bool> isPrime(maxN + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxN; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxN; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int nonSpecialCount(int l, int r) {
        int upper = std::ceil(std::sqrt(r));
        int lower = std::floor(std::sqrt(l));

        if (std::sqrt(l) != int(std::sqrt(l))) {
            lower = lower + 1;
        }

        if (std::sqrt(r) != int(std::sqrt(r))) {
            upper = upper - 1;
        }

        std::vector<bool> isPrime = sieve(upper);

        int count = 0;
        for (int i = lower; i <= upper; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }

        return r - l + 1 - count;
    }
};
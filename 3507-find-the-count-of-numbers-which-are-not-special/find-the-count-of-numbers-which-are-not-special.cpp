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

    int nonSpecialCount(int l, int r) {
        int upper = std::ceil(std::sqrt(r));
        int lower = std::floor(std::sqrt(l));

        if (std::sqrt(l) != int(std::sqrt(l))) {
            lower = lower + 1;
        }

        if (std::sqrt(r) != int(std::sqrt(r))) {
            upper = upper - 1;
        }

        int count = 0;

        for (int i = lower; i <= upper; ++i) {
            if (isPrime(i)) {
                count++;
            }
        }

        return r - l + 1 - count;
    }
};
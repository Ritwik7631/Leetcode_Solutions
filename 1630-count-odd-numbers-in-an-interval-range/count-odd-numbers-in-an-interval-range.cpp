class Solution {
public:
    int countOdds(int low, int high) {
        int len = high - low + 1;
        int base = len / 2;
        if (low % 2 == 1 && high % 2 == 1) base++; // both odd → +1
        return base;

    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        if(n == 1) return x;

        if(x == 0) return 0;

        bool flip = n < 0;

        int rem = abs(n);
        double ans = 1;
        while(rem > 0)
        {
            if(rem % 2 == 1)
            {
                ans *= x;
                rem--;
            }
            else
            {
                x *= x;
                rem /= 2;
            }
        }

        if(flip) return 1/ans;

        return ans;
    }

};
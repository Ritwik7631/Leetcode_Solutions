class Solution {
public:
    double fn(double base, int exp)
    {
        if(exp == 0) return 1.0;

        double ans = 1.0;

        if(exp % 2 == 0)
        {
            ans *= fn(base*base, exp/2.0);
        }
        else
        {
            ans *= (base * fn(base*base, exp/2.0));
        }

        return ans;
    }

    double myPow(double x, int n) {
        double ans = fn(x,n);

        if(n < 0) return 1.0/ans;

        return ans;
    }
};
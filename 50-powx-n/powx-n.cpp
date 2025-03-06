class Solution {
public:
    double fn(double x, int n)
    {
        if(n == 0) return 1;

        double ans = 1.0;

        double base = x;
        int exp = n;

        if(exp % 2 == 0)
        {
            ans = ans * fn(base*base, exp/2);
        }
        else
        {
            ans = ans * base;
            ans = ans * fn(base*base, exp/2); 
        }

        return ans;
    }

    double myPow(double x, int n) {
        double ans = fn(x, n);    

        if(n < 0) return 1.0/ans;

        return ans;
    }
};
const long long mod = 1e9 + 7;
class Solution {
public:
    long long power(long long base, long long exp)
    {
        if(exp == 0) return 1;

        if(exp % 2 == 1)
        {
            int temp = exp - 1;
            temp /= 2;

            return (base % mod * power((base % mod * base % mod), temp) % mod) % mod;
        }
        else
        {
            return power(((base % mod * base % mod) % mod), exp/2);
        }
    }

    long long factorial(long long x, vector<long long> &fact)
    {
        if(x <= 1) return 1;

        if(x == 2) return 2;

        if(fact[x] != -1) return fact[x];

        return fact[x] = (x % mod * factorial(x-1, fact) % mod) % mod;
    }

    int distanceSum(int m, int n, int k) {
        long long x = (n % mod * n % mod * m % mod * ((m % mod * m % mod - 1 + mod) % mod) % mod) % mod;
        long long y = (m % mod * m % mod * n % mod * ((n % mod * n % mod - 1 + mod) % mod) % mod) % mod;

        vector<long long> fact(n * m + 1, -1);

        long long A = factorial(n*m-2, fact);
        long long B = factorial(n*m-k, fact);
        long long C = factorial(k-2, fact);

        long long denominator = (B % mod * C % mod) % mod;

        // denominator^-1 => denominator^mod-2 using fermat's theorem

        long long converted_denom = power(denominator, mod - 2);

        long long d = (x % mod * power(6, mod - 2) % mod) % mod +
                      (y % mod * power(6, mod - 2) % mod) % mod;

        return (d % mod * A % mod * converted_denom % mod) % mod;
    }
};
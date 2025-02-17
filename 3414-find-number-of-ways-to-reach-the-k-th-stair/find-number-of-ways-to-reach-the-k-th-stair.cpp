class Solution {
public:
    long long NCR(int n, int r)
    {
        long long ans = 1;

        for(int i = 1; i <= r; i++)
        {
            ans *= (n-i+1);
            ans /= i;
        }

        return ans;
    }

    int waysToReachStair(int k) {
        if(k == 0) return 2;

        int y = 0;

        int ans = 0;

        for(int y = 0; y <= 30; y++)
        {
            if(log2(y+k) == int(log2(y+k)))
            {
                int x = int(log2(y+k));
                ans += NCR(x+1,y);
            }
        }

        return ans;
    }
};
class Solution {
public:
    long long NCR(int n, int r)
    {
        long long ans = 1;

        int j = 1;
        for(int i = n; i >= n-r+1; i--)
        {
            ans *= i;
            ans /= j;
            j++;
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
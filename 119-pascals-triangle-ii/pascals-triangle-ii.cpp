class Solution {
public:
    long long NCR(int n, int r)
    {
        int a = n;
        int b = 1;

        long long ans = 1;

        while(b <= r)
        {
            ans *= a;

            ans /= b;

            a--;
            b++;
        }

        return ans;
    }

    vector<int> getRow(int n) {
        vector<int> temp;

        for(int c = 0; c <= n; c++)
        {
            temp.push_back(NCR(n, c));
        }

        return temp;
    }
};
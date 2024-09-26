class Solution {
public:
    void NCR(int n, vector<int> &temp)
    {
        int a = n;
        int b = 1;

        long long ans = 1;
        temp.push_back(1);

        while(b <= n)
        {
            ans *= a;

            ans /= b;

            temp.push_back(ans);

            a--;
            b++;
        }

        return;
    }

    vector<int> getRow(int n) {
        vector<int> temp;

        NCR(n, temp);

        return temp;
    }
};
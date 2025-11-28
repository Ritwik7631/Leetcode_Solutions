class Solution {
public:
    int mod = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<int> ans;
        ans.reserve(q);

        vector<long long> prefix_value(n+1, 0);
        vector<int> prefix_len(n+1, 0);

        vector<int> prefix_sum(n+1, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];

            prefix_value[i+1] = prefix_value[i];
            prefix_len[i+1]   = prefix_len[i];

            if (c != '0') {
                prefix_value[i+1] = (prefix_value[i] * 10 + (c - '0')) % mod;
                prefix_len[i+1]++;
            }

            prefix_sum[i+1] = prefix_sum[i] + (c - '0');
        }

        // Precompute 10^k mod mod
        vector<long long> pow10(n+1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i-1] * 10) % mod;

        for (auto &qr : queries) {
            int l = qr[0];
            int r = qr[1];

            int rsum = prefix_sum[min(r+1, n)];
            int lsum = prefix_sum[l];
            int pre_sum = rsum - lsum;

            long long rv = prefix_value[min(r+1, n)];
            long long lv = prefix_value[l];

            int a = prefix_len[min(r+1, n)];
            int b = prefix_len[l];

            // shift l by (a-b)
            long long shift = pow10[a - b];

            long long x = (rv - (lv * shift % mod) + mod) % mod;

            long long val = (1LL * pre_sum * x) % mod;

            ans.push_back((int)val);
        }

        return ans;
    }
};

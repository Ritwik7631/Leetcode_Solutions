class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();

        vector<int> parity(10, 0);

        string key(10, '0');
        unordered_map<string, int> last_seen;
        last_seen[key] = -1;

        int ans = 0;

        for(int i = 0; i < n; i++){
            int d = s[i] - '0';

            parity[d] ^= 1;

            for(int j = 0; j < 10; j++) key[j] = parity[j] ? '1' : '0';

            if (last_seen.count(key)) ans = max(ans, i - last_seen[key]);
            else last_seen[key] = i;

            for (int b = 0; b < 10; b++) {
                key[b] = (key[b] == '0' ? '1' : '0');
                if (last_seen.count(key)) ans = max(ans, i - last_seen[key]);
                key[b] = (key[b] == '0' ? '1' : '0'); // revert
            }
        }

        return ans;
    }
};
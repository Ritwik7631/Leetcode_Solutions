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

            for(int j = 0; j < 10; j++){
                if(parity[j] == 1){
                    key[j] = '1';
                }
                else{
                    key[j] = '0';
                }
            }

            if (last_seen.count(key)) ans = max(ans, i - last_seen[key]);
            else last_seen[key] = i;

            for (int b = 0; b < 10; b++) {
                if (key[b] == '0')
                    key[b] = '1';
                else
                    key[b] = '0';

                if (last_seen.count(key))
                    ans = max(ans, i - last_seen[key]);

                if (key[b] == '0')
                    key[b] = '1';
                else
                    key[b] = '0';
            }
        }

        return ans;
    }
};
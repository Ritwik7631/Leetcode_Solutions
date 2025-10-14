class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> parity;
        parity['a'] = 0;
        parity['e'] = 0;
        parity['i'] = 0;
        parity['o'] = 0;
        parity['u'] = 0;

        string key(5, '0');

        unordered_map<string, int> last_seen;
        last_seen[key] = -1;

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(parity.count(s[i])) parity[s[i]] ^= 1; 

            int k = 0;
            for(auto [x,v] : parity){
                if(v){
                    key[k] = '1';
                }
                else{
                    key[k] = '0';
                }
                k++;
            }

            if(last_seen.count(key)) ans = max(ans, i - last_seen[key]);
            else last_seen[key] = i;
        }

        return ans;
    }
};
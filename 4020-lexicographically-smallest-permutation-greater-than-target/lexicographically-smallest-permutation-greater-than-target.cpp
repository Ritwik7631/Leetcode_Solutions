class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        vector<int> bank(26, 0);

        for (auto a : s) bank[a - 'a']++;

        int i = -1;
        for (char a : target) {
            i++;
            if (bank[a - 'a'] > 0) {
                bank[a - 'a']--;
                ans += a;
            } else {
                break;
            }
        }

        // do NOT return on full match; we still need next permutation if it exists
        if (ans.size() != target.size()) {
            // try to bump at the mismatch position i
            int need = target[i] - 'a';
            for (int k = need + 1; k < 26; k++) {
                if (bank[k] > 0) {
                    ans += char('a' + k);
                    bank[k]--;
                    for (int t = 0; t < 26; t++) ans += string(bank[t], 'a' + t);
                    return ans;
                }
            }
        }

        // backtrack into the matched prefix to find first bumpable spot
        for (int j = (int)ans.size() - 1; j >= 0; j--) {
            int cur = ans[j] - 'a';
            bank[cur]++; // put back
            for (int k = cur + 1; k < 26; k++) {
                if (bank[k] > 0) {
                    ans[j] = char('a' + k);
                    bank[k]--;
                    ans = ans.substr(0, j + 1);         // drop old suffix
                    for (int t = 0; t < 26; t++) ans += string(bank[t], 'a' + t);
                    return ans;
                }
            }
        }

        return "";
    }
};

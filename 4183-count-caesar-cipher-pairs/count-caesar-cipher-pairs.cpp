class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();

        unordered_map<int,string> word_to_sig;

        for(int idx = 0; idx < n; idx++){
            string a = words[idx];
            string sig = "";
            for(int i = 1; i < a.size(); i++){
                sig += to_string((a[i] - a[0] + 26) % 26);
            }
            word_to_sig[idx] = sig;
        }

        unordered_map<string,int> sig_freq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += sig_freq[word_to_sig[i]];
            sig_freq[word_to_sig[i]]++;
        }

        
        return ans;
    }
};
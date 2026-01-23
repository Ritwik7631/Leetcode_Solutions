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
        vector<unordered_map<string,int>> prefix;

        for(int i = 0; i < n; i++){
            sig_freq[word_to_sig[i]] += 1;
            prefix.push_back(sig_freq);
        }

        long long ans = 0;

        for(int i = 1; i < n; i++){
            string sig_j = word_to_sig[i];

            if(prefix[i-1].count(sig_j)){
                ans += (long long)prefix[i-1][sig_j];
            }
        }
        
        return ans;
    }
};
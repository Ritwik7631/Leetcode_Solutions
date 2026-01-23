class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> sig_freq;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            string sig_j = "";
            for(int k = 1; k < words[i].size(); k++){
                sig_j += to_string((words[i][k] - words[i][0] + 26)%26);
            }

            ans += sig_freq[sig_j];
            sig_freq[sig_j]++;
        }

        
        return ans;
    }
};
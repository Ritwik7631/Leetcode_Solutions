class Solution {
public:
    long long numOfSubsequences(string s) {
        long long orig = 0;
        int n = s.size();

        vector<long long> prefixL(n+1, 0), suffixT(n+1, 0);
        for(int i = 0; i < n; i++) {
            prefixL[i+1] = prefixL[i] + (s[i] == 'L');
        }
        for(int i = n-1; i >= 0; i--) {
            suffixT[i] = suffixT[i+1] + (s[i] == 'T');
        }

        for(int i = 0; i < n; i++){
            if(s[i] == 'C'){
                orig += prefixL[i] * suffixT[i+1];
            }
        }

        // === CHANGED: sum all CT pairs for gainL instead of taking max over single C ===
        long long gainL = 0;  // was INT_MIN
        for(int i = 0; i < n; i++){
            if(s[i] == 'C'){
                gainL += suffixT[i+1];  // sum, not max
            }
        }

        // === CHANGED: sum all LC pairs for gainT instead of taking max over single C ===
        long long gainT = 0;  // was INT_MIN
        for(int i = 0; i < n; i++){
            if(s[i] == 'C'){
                gainT += prefixL[i];    // sum, not max
            }
        }

        // gain from inserting 'C' stays as max(prefixL[i] * suffixT[i])
        long long gainC = 0;  // initialize to 0
        for(int i = 0; i <= n; i++){
            long long val = prefixL[i] * suffixT[i];
            gainC = max(gainC, val);
        }

        return orig + max({0LL, gainL, gainC, gainT});
    }
};

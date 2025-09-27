class Solution {
public:
    vector<int> compute_prefix(string& s){
        int n = s.size();

        vector<int> pi(n, 0);

        int k = 0;

        for(int i = 1; i < n; i++){
            while(k > 0 && s[k] != s[i]) k = pi[k-1];

            if(s[k] == s[i]) k++;

            pi[i] = k;
        }

        return pi;
    }

    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1) return false;

        vector<int> pi = compute_prefix(s);

        if(pi.back() != 0 && s.size() % (s.size()-pi.back()) == 0) return true;

        return false;
    }
};
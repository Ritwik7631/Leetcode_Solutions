class Solution {
public:
    vector<int> prefix_function(string& P){
        int m = P.size();
        vector<int> pi(m, 0);
        int k = 0;

        for(int q = 1; q < m; q++){
            while(k > 0 && P[k] != P[q]) k = pi[k-1];

            if(P[k] == P[q]) k++;

            pi[q] = k;
        }

        return pi;
    }

    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        if(n == 0) return 0;

        vector<int> pi = prefix_function(needle);

        int j = 0;

        for(int i = 0; i < m; i++){
            while(j > 0 && needle[j] != haystack[i]) j = pi[j-1];

            if(needle[j] == haystack[i]) j++;

            if(j == n) return i - n + 1;
        }

        return -1;
    }
};
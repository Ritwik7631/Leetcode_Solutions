class Solution {
public:
    int expand(int l, int r, string& s){
        int n = s.size();

        while(l >= 0 && r < n){
            if(s[l] == s[r]){
                l--;
                r++;
            }
            else break;
        }

        // palindrome len until now

        int len = r - l - 1;

        if(len == n) return n-1;

        // skip left;

        int aL = l-1;
        int aR = r;

        while(aL >= 0 && aR < n){
            if(s[aL] == s[aR]){
                aL--;
                aR++;
            }
            else break;
        }

        len = max(len, aR-aL-1);

        // skip right

        int bL = l;
        int bR = r+1;

        while(bL >= 0 && bR < n){
            if(s[bL] == s[bR]){
                bL--;
                bR++;
            }
            else break;
        }

        len = max(len, bR-bL-1);
        return len;
    }

    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, expand(i,i,s));
            if(i+1 < n) ans = max(ans, expand(i,i+1,s));
        }

        return ans;
    }
};
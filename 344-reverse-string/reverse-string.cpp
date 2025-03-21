class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int n = s.size();

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }

        return;
    }
};
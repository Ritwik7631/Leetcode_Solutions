class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        for(int i = 0; i < m; i++){
            string potential = haystack.substr(i, n);

            if(potential == needle) return i;
        }

        return -1;
    }
};
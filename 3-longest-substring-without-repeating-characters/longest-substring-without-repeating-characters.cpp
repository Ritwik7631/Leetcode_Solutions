class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> prev;
        int maxlen = 0, start = 0;
        int n = s.size();

        for(int end = 0; end < n; end++)
        {
            if(prev.find(s[end]) != prev.end() && prev[s[end]] >= start)
            {
                start = prev[s[end]] + 1;
            }

            prev[s[end]] = end;

            maxlen = max(maxlen, end-start+1);
        }

        return maxlen;
    }
};
class Solution {
public:
    bool fn(int i, int j, string &p, string &s) {
        // Base cases
        if(i < 0 && j < 0) return true;         // Both pattern and string are exhausted.
        if(i < 0 && j >= 0) return false;        // Pattern is empty but string is not.
        if(j < 0) {                            // String is empty.
            // The remaining pattern must form valid "x*" pairs to match an empty string.
            if(i > 0 && p[i] == '*')
                return fn(i - 2, j, p, s);
            return false;
        }
        
        // Direct match or '.' wildcard.
        if(p[i] == s[j] || p[i] == '.')
            return fn(i - 1, j - 1, p, s);
        
        // Handling '*' operator.
        if(p[i] == '*')
            return fn(i - 2, j, p, s) ||
                ((p[i - 1] == s[j] || p[i - 1] == '.') && fn(i, j - 1, p, s));
        
        return false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        return fn(n-1, m-1, p, s);
    }
};
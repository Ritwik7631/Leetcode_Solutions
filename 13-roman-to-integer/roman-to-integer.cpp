class Solution {
public:
    int romanToInt(string s) {
        static const int lut[256] = {
            /* 'C' */ ['C'] = 100,
            /* 'D' */ ['D'] = 500,
            /* 'I' */ ['I'] = 1,
            /* 'L' */ ['L'] = 50,
            /* 'M' */ ['M'] = 1000,
            /* 'V' */ ['V'] = 5,
            /* 'X' */ ['X'] = 10
        };

        int ans = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            int v = lut[(unsigned char)s[i]];
            if (i + 1 < s.size() && v < lut[(unsigned char)s[i + 1]]) ans -= v;
            else ans += v;
        }
        return ans;
    }
};

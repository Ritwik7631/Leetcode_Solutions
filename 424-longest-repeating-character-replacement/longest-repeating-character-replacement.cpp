class Solution {
public:
    bool convertible(char b, int k, unordered_map<char,int> &freq)
    {
        int total = 0;
        int mx = 0;
        for(auto p : freq)
        {
            total += p.second;
            mx = max(mx, p.second);
        }
        
        total += 1;
        int simulatedFreq = freq[b] + 1;
        mx = max(mx, simulatedFreq);
        
        int to_be_converted = total - mx;
        return k >= to_be_converted;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        unordered_map<char,int> freq;

        int a = 0;

        for (int b = 0; b < n; b++)
        {
            while (!convertible(s[b], k, freq))
            {
                freq[s[a]]--;  
                a++;
            }
            freq[s[b]]++;
            ans = max(ans, b - a + 1);
        }

        return ans;   
    }
};

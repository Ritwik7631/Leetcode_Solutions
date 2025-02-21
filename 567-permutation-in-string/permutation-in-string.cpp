class Solution {
public:
    bool addb(vector<int> &s1freq, vector<int> &s2freq, char b)
    {
        return s2freq[b - 'a'] < s1freq[b - 'a'];
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> s1freq(26, 0);
        
        for(auto a : s1)
        {
            s1freq[a - 'a']++;
        }

        vector<int> s2freq(26, 0);

        int a = 0;
        int n = s2.size();

        for(int b = 0; b < n; b++)
        {
            if(s1freq[s2[b] - 'a'] == 0)
            {
                s2freq = vector<int>(26,0); // we reset because s2freq has to be an exact permutation of s1freq and if s2[b] is not in s1 then we reset
                a = b+1;
                continue;
            }

            while(addb(s1freq, s2freq, s2[b]) == false)
            {
                s2freq[s2[a] - 'a']--;
                a++;
            }

            s2freq[s2[b] - 'a']++;
            
            if(s1freq == s2freq) return true;
        }

        return false;
    }
};
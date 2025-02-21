class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 1;
        int n = s.size();

        if(n==0) return 0;
        
        int a = 0;

        set<char> st;

        for(int b = 0; b < n; b++)
        {           
            while(st.find(s[b]) != st.end())
            {
                st.erase(s[a]);
                a++;
            }

            st.insert(s[b]);

            ans = max(ans, b-a+1);
        }

        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(auto a : st)
        {
            if(st.find(a-1) == st.end()) 
            {
                int count = 1;
                while(st.find(a+count) != st.end())
                {
                    count++;
                }
                ans = max(ans, count);
            }
        }
        
        return ans;
        
    }
};

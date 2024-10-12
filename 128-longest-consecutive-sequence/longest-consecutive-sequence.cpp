class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(auto a : nums) st.insert(a);

        int longest = 0;

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(st.count(nums[i]-1) == 1)
            {
                continue;
            }
            count = 1;

            int x = nums[i];

            while(st.count(x+1))
            {
                count++;
                x++;
                
            }
            longest = max(longest, count);
        }

        return longest;
    }
};
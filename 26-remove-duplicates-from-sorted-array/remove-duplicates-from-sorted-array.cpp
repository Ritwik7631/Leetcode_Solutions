class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        set<int> st;

        for(auto a : nums)
        {
            st.insert(a);
        }

        int i = 0;

        for(auto a : st)
        {
            nums[i] = a;
            i++;
        }

        int m = st.size();

        return m;
    }
};
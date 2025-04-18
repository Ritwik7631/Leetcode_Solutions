class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> st;

        int n = nums.size();

        for(auto a : nums)
        {
            st.insert(a);
        }

        int ans;

        for(int i = 0; i < k; i++)
        {
            auto it = st.begin();
            int val = *it;
            ans = val;
            st.erase(it);
        }

        return ans;
    }
};
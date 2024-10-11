class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        if(n == 1) return 1;

        sort(nums.begin(), nums.end());

        set<int> st = {nums.begin(), nums.end()};

        nums = {st.begin(), st.end()};

        n = nums.size();

        int count = 1;
        int ans = 1;

        for(int i = 1; i < n; i++)
        {
            // cout << "nums[i]: " << nums[i] << endl;
            // cout << "nums[i-1]: " << nums[i-1] << endl;
            // cout << "count: " << count << endl;
            if(nums[i] - nums[i-1] == 1)
            {
                count++;
                ans = max(ans, count);
            }
            else
            {
                count = 1;
            }
        }

        return ans;

    }
};
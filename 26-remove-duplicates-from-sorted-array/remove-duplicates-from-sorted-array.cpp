class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto a : nums)
        {
            mp[a]++;
        }

        nums.clear();

        for(auto a : mp)
        {
            nums.push_back(a.first);
        }

        sort(nums.begin(), nums.end());

        int m = nums.size();

        for(int i = 0; i < n-m; i++)
        {
            nums.push_back(INT_MAX);
        }

        return m;
    }
};
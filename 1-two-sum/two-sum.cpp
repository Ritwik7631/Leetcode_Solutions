class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, vector<int>> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < n; i++)
        {
            int comp = target - nums[i];

            for(auto a : mp[comp])
            {
                if(a != i) return {i,a};
            }
        }

        return {0,0};
    }
};
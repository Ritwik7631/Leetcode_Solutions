class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                for(auto a : mp[target-nums[i]])
                {
                    if(a != i) return {a,i};
                }
            }
        }

        return {0,0};
    }
};
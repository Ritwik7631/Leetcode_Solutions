class Solution {
public:
    vector<vector<int>> fn(int i, int rem, vector<int>& nums, vector<int>& curr)
    {
        vector<vector<int>> ans;

        if(rem == 0)
        {
            ans.push_back(curr);
            return ans;
        }

        if(i < 0)
        {
            return ans;
        }

        if(rem - nums[i] >= 0)
        {
            curr.push_back(nums[i]);
            vector<vector<int>> pick = fn(i, rem - nums[i], nums, curr);
            curr.pop_back();

            for(auto a : pick) ans.push_back(a);
        }

        vector<vector<int>> notpick = fn(i-1, rem, nums, curr);
        for(auto a : notpick) ans.push_back(a);

        return ans;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> curr;
        return fn(n-1, target, candidates, curr);
    }
};
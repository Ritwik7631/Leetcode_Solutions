class Solution {
public:
    vector<vector<int>> ans;

    void fn(int i, vector<int> &nums, int &rem, vector<int> &temp)
    {
        if(rem == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(i == nums.size()) return;

        temp.push_back(nums[i]);
        if(rem - nums[i] >= 0)
        {
            rem -= nums[i];
            fn(i, nums, rem, temp);
            rem += nums[i];
        }

        temp.pop_back();
        fn(i+1, nums, rem, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        int rem = target;
        fn(0, candidates, rem, temp);

        return ans;
    }
};
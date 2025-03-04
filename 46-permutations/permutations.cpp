class Solution {
public:
    vector<vector<int>> res;

    void fn(int i, vector<int> &nums, vector<int> &curr, vector<bool> &used)
    {
        if(curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }

        for(int j = 0; j < nums.size(); j++)
        {
            if(used[j] == true) continue;

            curr.push_back(nums[j]);
            used[j] = true;
            fn(i+1, nums, curr, used);
            used[j] = false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        fn(0, nums, curr, used);

        return res;
    }
};
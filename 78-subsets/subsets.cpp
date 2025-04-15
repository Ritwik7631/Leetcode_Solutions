class Solution {
public:
    void fn(int i, vector<int>& nums, vector<int> temp, vector<vector<int>>& result)
    {
        if(i == nums.size())
        {
            result.push_back(temp);
            return;
        }

        // pick 
        temp.push_back(nums[i]);
        fn(i+1, nums, temp, result);
        temp.pop_back();

        // not pick
        fn(i+1, nums, temp, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        fn(0, nums, temp, result);

        return result;
    }
};
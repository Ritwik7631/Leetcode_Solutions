class Solution {
public:
    vector<vector<int>> ans;
    void fn(int i, vector<int>& nums, vector<int> &curr)
    {
        if(i < 0)
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        fn(i-1, nums, curr);
        curr.pop_back();

        fn(i-1, nums, curr);

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        fn(nums.size()-1, nums, arr);

        return ans;
    }
};
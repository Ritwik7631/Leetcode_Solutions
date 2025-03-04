class Solution {
public:
    vector<vector<int>> res;

    void fn(int i, vector<int>& nums, vector<int>& curr)
    {
        res.push_back(curr);

        for(int j = i; j < nums.size(); j++)
        {
            curr.push_back(nums[j]);
            fn(j+1, nums, curr);
            curr.pop_back();

            while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> curr;

        fn(0, nums, curr);

        return res;

    }
};
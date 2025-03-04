class Solution {
public:
    set<vector<int>> res;

    void fn(int i, vector<int>& nums, vector<int>& curr)
    {
        if(i < 0)
        {
            res.insert(curr);
            return;
        }


        curr.push_back(nums[i]);
        fn(i-1, nums, curr);
        curr.pop_back();
        

        fn(i-1, nums, curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        int n = nums.size();
        fn(n-1, nums, curr);

        vector<vector<int>> ans;

        for(auto a : res) ans.push_back(a);

        return ans;
    }
};
class Solution {
public:
    set<vector<int>> st;

    void fn(int i, vector<int> &nums, vector<int> &temp)
    {
        if(i == nums.size()) return;

        temp.push_back(nums[i]);
        st.insert(temp);
        fn(i+1, nums, temp);

        temp.pop_back();
        fn(i+1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        fn(0, nums, temp);

        // set<vector<int>> arr;

        // for(auto a : st)
        // {
        //     sort(a.begin(), a.end());
        //     arr.insert(a);
        // }

        vector<vector<int>> ans(st.begin(), st.end());

        ans.push_back({});
        
        return ans;
    }   
};
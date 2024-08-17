class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return nums;

        int x = 0;

        for(int i = 1; i < k; i++)
        {
            if(nums[i] != nums[i-1] + 1) x++;
        }

        vector<int> ans;

        if(x == 0)
        {
            ans.push_back(nums[k-1]);
        }
        else
        {
            ans.push_back(-1);
        }

        for(int i = k; i < n; i++)
        {
            if(nums[i] != nums[i-1] + 1) x++;

            if(nums[i-k+1] != nums[i-k] + 1) x--;

            if(x == 0) ans.push_back(nums[i]);
            else ans.push_back(-1);
        }

        return ans;
    }
};
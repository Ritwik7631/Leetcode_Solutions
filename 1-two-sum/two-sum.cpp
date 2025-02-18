class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
           for(auto j = 0; j < nums.size() && i != j; j++)
           {
                if(nums[i] + nums[j] == target) return {i,j};
           } 
        }

        return {0,0};
    }
};
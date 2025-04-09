class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> pre_ans;

        for(int i = 0; i < n-2; i++)
        {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            
            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == 0)
                {
                    multiset<int> temp = {nums[i], nums[left], nums[right]};
                    vector<int> actual(temp.begin(), temp.end());
                    pre_ans.insert(actual);
                    
                    while(left < right && nums[left] == nums[left+1]) left++;

                    while(left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
                else if(sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
            
        }

        vector<vector<int>> ans(pre_ans.begin(), pre_ans.end());
        return ans;

        // -4 -1 -1 0 1 2
        //     i  j     lr
    }
};
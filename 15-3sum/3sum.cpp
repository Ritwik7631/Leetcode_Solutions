class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++)
        {
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;

            // cout << "i: " << i << endl;
            // cout << "nums[i]: " << nums[i] << endl;

            int j = i + 1;
            int k = nums.size()-1;

            while(j < k)
            {
                // cout << "j: " << j << " " << "k: " << k << endl;
                // cout << "nums[j]: " << nums[j] << " " << "nums[k]: " << nums[k] << endl;
                int sum = nums[i] + nums[j] + nums[k];
                // cout << "sum: " << sum << endl;
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < nums.size() && j-1 >= i+1 && nums[j] == nums[j-1]) j++;
                    while(k >= i+1 && k+1 < nums.size() && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    // 2*x = total_sum - outlier
    int getLargestOutlier(vector<int>& nums) {
        
        int total = accumulate(nums.begin(), nums.end(),0);

        // cout << "total: " << total << endl;

        unordered_map<int,int> mp;

        for(auto a : nums) mp[a]++;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            // cout << "nums[i]: " << nums[i] << endl;

            if(((total - nums[i]) & 1) != 0) continue;

            int temp = (total - nums[i])/2;

            // cout << "temp: " << temp << endl;
            if (mp[temp] > 0)
            {    
                if (temp == nums[i] && mp[temp] == 1) continue;

                if(nums[i] > ans)
                {
                    ans = nums[i];
                }
            }
        }

        return ans;
    }
};
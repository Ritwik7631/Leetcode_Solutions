class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int> mp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        // for(auto a : nums) cout << a << " ";

        cout << endl;

        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++)
        {   
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < nums.size(); j++)
            {
                if(j-1 >= i+1 && nums[j] == nums[j-1]) continue;

                int missing = 0 - (nums[i] + nums[j]);

                if(missing < nums[j]) continue;

                mp[nums[i]]--;
                mp[nums[j]]--;
                // cout << "missing: " << missing << endl;
                // cout << "mp[missing]: " << mp[missing] << endl;

                if(mp[missing] > 0 && missing >= nums[j])
                {
                    vector<int> temp = {nums[i], nums[j], missing};
                    ans.push_back(temp);
                }

                mp[nums[i]]++;
                mp[nums[j]]++;
                
            }
        }

        return ans;
    }
};
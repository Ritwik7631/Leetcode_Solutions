class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int a = 0; a < n; a++)
        {
            if(a > 0 && nums[a] == nums[a-1]) continue;

            int b = a + 1;
            int c = n - 1;

            while(b < c)
            {
                int x = nums[a] + nums[b] + nums[c];
                if(x == 0)
                {
                    ans.push_back({nums[a], nums[b], nums[c]});

                    while(b < c && nums[b] == nums[b+1]) b++;

                    while(b < c && nums[c] == nums[c-1]) c--;

                    b++;
                    c--;
                }
                else if(x < 0)
                {
                    b++;
                }
                else
                {
                    c--;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int i = 1;
        int j = 1;

        while(i < n)
        {
            while(i < n && nums[i] == nums[i-1])
            {
                i++;
            }

            if(i < n)
            {
                nums[j] = nums[i];
                j++;
                i++;
            }
        }

        return j;
    }
};
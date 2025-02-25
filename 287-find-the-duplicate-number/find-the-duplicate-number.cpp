class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = 0;
        int hare = 0;

        int n = nums.size();

        while(tortoise < n && hare < n)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];

            if(hare == tortoise)
            {
                int tortoise1 = 0;
                int tortoise2 = hare;

                while(nums[tortoise1] != nums[tortoise2])
                {
                    tortoise1 = nums[tortoise1];
                    tortoise2 = nums[tortoise2];
                }

                if(nums[tortoise1] == nums[tortoise2]) return nums[tortoise2];
            }
        }

        return 0;
    }
};
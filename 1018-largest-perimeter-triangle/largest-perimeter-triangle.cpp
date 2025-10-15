class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        /*
            a  > c - b
            a  > b - c

            -> a > |b-c|
            
            b + c > a

            -> a < b+c
        */

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = n-1; i >= 2; i--){
            if(nums[i-2] + nums[i-1] > nums[i]) return nums[i] + nums[i-1] + nums[i-2];
        }

        return 0;


    }
};
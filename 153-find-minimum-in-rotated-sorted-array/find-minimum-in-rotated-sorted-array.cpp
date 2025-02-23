class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l < r)
        {
            int mid = l + (r-l)/2;

            cout << "l: " << l << " " << "r: " << r << endl;

            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return nums[l];
    }
};
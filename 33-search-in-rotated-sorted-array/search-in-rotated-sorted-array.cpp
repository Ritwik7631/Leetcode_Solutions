class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[l] <= nums[mid]) { 
                if(target >= nums[l] && target < nums[mid])
                    r = mid; 
                else
                    l = mid + 1; 
            }
            else if(nums[l] > nums[mid]) {
                if(target >= nums[mid] && target <= nums[r])
                    l = mid + 1;  
                else
                    r = mid;
            }
        }
        
        return (nums[l] == target) ? l : -1;
    }
};

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i + 2 * k > n) continue;
            
            bool increasing1 = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    increasing1 = false;
                    break;
                }
            }
            
            bool increasing2 = true;
            for (int j = i + k; j < i + 2 * k - 1; j++) {
                if (nums[j] >= nums[j + 1]) {
                    increasing2 = false;
                    break;
                }
            }
            
            if (increasing1 && increasing2) return true;
        }
        
        return false;
    }
};

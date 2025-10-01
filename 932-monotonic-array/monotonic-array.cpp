class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        stack<int> inc, dec;

        inc.push(nums[0]);
        dec.push(nums[0]);

        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] >= inc.top()) inc.push(nums[i]);
        }

        for(int i = 1; i < n; i++){
            if(nums[i] <= dec.top()) dec.push(nums[i]);
        }

        if(inc.size() == n || dec.size() == n) return true;

        return false;
    }
};
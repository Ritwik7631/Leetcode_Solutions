class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_max(n, -1), suffix_min(n, -1);

        int mx = INT_MIN;

        for(int i = 0; i < n; i++){
            prefix_max[i] = max(mx, nums[i]);
            mx = max(mx, nums[i]);
        }

        int mn = INT_MAX;

        for(int i = n-1; i >= 0; i--){
            suffix_min[i] = min(mn, nums[i]);
            mn = min(mn, nums[i]);
        }

        int start = 0;
        int i = 0;
        vector<int> ans(n, 0);
        while(i <= n-2){
            if(prefix_max[i] <= suffix_min[i+1]){
                for(int j = start; j <= i; j++) ans[j] = prefix_max[i];

                start = i+1;
            }
            
            i++;
        }

        for(int j = start; j <= n-1; j++) ans[j] = prefix_max[n-1];

        return ans;


    }
};
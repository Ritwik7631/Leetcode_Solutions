class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        /*
            nums arr
            int k

            Is it possible to partition ALL elements into >= 1 groups
            - each group contains only k distinct elements 
            - each element is used only once when putting in groups (no reusing)
        
        */

        int n = nums.size();

        if(n % k != 0) return false;

        unordered_map<int,int> mp;

        for(auto a : nums) mp[a]++;

        int groups = n/k;

        for(auto [k,v] : mp){
            if(v > groups) return false;
        }

        return true;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;
        freq[0] = 1;

        int ans = 0;

        int current = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1) current++;

            if(freq.count(current - k)) ans += freq[current-k];
            freq[current]++;
        }

        return ans;
    }
};
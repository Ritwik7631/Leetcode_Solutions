class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> freq;
        freq[0] = 1;

        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 1){
                count++;
            }

            if(freq.count(count - k)) ans += freq[count-k];
            freq[count]++;
        }

        return ans;
    }
};
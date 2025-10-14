class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;

        unordered_map<int,int> prev_seen;
        prev_seen[0] = 1; 

        int count = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(prev_seen.count(sum - target)){
                count++;
                prev_seen.clear();
                prev_seen[0] = 1;
                sum = 0;
            }
            else{
                prev_seen[sum] = i;
            }
        }

        return count;
    }
};
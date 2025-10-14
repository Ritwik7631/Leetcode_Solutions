class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int current = 0;

        unordered_map<int,int> last_seen;
        last_seen[0] = -1;

        for(int i = 0; i < n; i++){
            current = (current+nums[i]) % k;

            if(last_seen.count(current)){
                if(i - last_seen[current] >= 2) return true;
            }
            else{
                last_seen[current] = i;
            }
        }

        return false;
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> last_seen;
        last_seen[0] = -1;

        int ans = 0;

        int current = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                current += 1;
            }
            else{
                current -= 1;
            }

            if(!last_seen.count(current)) last_seen[current] = i;
            else{
                ans = max(ans, i - last_seen[current]);
            }
        }

        return ans;


    }
};
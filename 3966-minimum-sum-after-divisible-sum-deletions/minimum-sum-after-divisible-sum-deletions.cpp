class Solution {
public:
    long long fn(int i, vector<int>& nums, vector<long long>& last, int k, vector<long long>& dp){

        if(i <= 0) return 0;

        if(dp[i] != -1) return dp[i];

        long long pick = LLONG_MAX;
        long long notpick = fn(i-1, nums, last, k, dp) + nums[i-1];

        if(last[i] != -1) pick = fn(last[i], nums, last, k, dp);

        return dp[i] = min(pick, notpick);
    }


    long long minArraySum(vector<int>& nums, int k) {
        /*
            nums = [3,1,4,1,5], k = 3
            pref = [0,3,4,8,9,14]
      prefix_mod = [0,0,1,2,0,2]

        dp[i] returns the minimum leftover sum from 0 to i-1

        dp[n] should give the answer

        if(i < 0) return 0

        delete = fn(last[i]);

        notdelete = fn(i-1) + nums[i];

        return min(delete, notdelete)

        last[i] returns the last index where the mod is the same
        */

        int n = nums.size();

        vector<long long> pref(n+1, 0);

        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + (long long)nums[i];
        }

        vector<long long> prefix_mod(n+1, 0);

        for(int i = 0; i < pref.size(); i++){
            prefix_mod[i] = (long long)pref[i] % k;
        }

        vector<long long> last(n+1, -1); // last[i] returns the last strictly lower index where pref_mod[lower_index] = pref_mod[i]
        vector<long long> last_remainder(k, -1);

        for(int i = 0; i <= n; i++){
            int r = prefix_mod[i];
            last[i] = last_remainder[r];
            last_remainder[r] = i;
        }

        vector<long long> dp(n+1, -1);

        return fn(n, nums, last, k, dp);

    }
};
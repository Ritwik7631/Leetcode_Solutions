class Solution {
public:
    // fn(i): min leftover on nums[0..i], using precomputed prev-prefix jumps in `last`
    long long fn(int i, std::vector<int>& nums, int k,
                 std::vector<long long>& prefix, std::vector<int>& last, vector<long long>& memo) {
        if (i < 0) return 0;

        if(memo[i] != LLONG_MIN) return memo[i];

        // not pick: keep nums[i]
        long long notpick = fn(i - 1, nums, k, prefix, last, memo) + nums[i];

        // pick: delete the block ending at i if there is a matching previous prefix
        long long pick = LLONG_MAX;
        int j = last[i];                    // j is a *prefix* index (0..i), or -1 if none
        if (j != -1) pick = fn(j - 1, nums, k, prefix, last, memo);

        return memo[i] = min(pick, notpick);
    }

    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }

        if (prefix[n] % k == 0) return 0;

        vector<int> last(n, -1);
        vector<int> lastRem(k, -1);
        lastRem[0] = 0;

        for(int i = 0; i < n; i++){
            int rem = (prefix[i+1]%k);
            last[i] = lastRem[rem];
            lastRem[rem] = i+1;
        }

        vector<long long> memo(n, LLONG_MIN);

        return fn(n-1, nums, k, prefix, last, memo);
    }
};
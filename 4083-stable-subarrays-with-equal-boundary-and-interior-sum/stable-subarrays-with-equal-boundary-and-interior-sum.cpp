class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();

        vector<long long> prefix(n+1, 0);

        for(int i = 0; i < n; i++) prefix[i+1] = prefix[i] + capacity[i];

        unordered_map<long long, unordered_map<long long,long long>> cnt;

        long long ans = 0;

        for(int r = 0; r < n; r++){

            if(r - 2 >= 0){
                int l = r-2;
                cnt[capacity[l]][prefix[l]]++;
            }

            long long need = prefix[r+1] - 3LL * capacity[r];

            if(cnt.count(capacity[r])){
                auto &mp = cnt[capacity[r]];
                if(mp.count(need)) ans += mp[need];
            }
        }

        return ans;
    }
};
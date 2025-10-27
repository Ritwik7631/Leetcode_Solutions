class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        long long ans = 0;

        unordered_map<int,vector<int>> last_seen; // value, indices

        vector<long long> prefix(capacity.begin(), capacity.end());

        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + capacity[i];
        }

        unordered_map<long long, unordered_map<long,long>> cnt;

        for(int i = 0; i < n; i++){

            if(i - 2 >= 0){
                int a = i-2;
                long long key = (a - 1 >= 0) ? prefix[a - 1] : 0;
                cnt[capacity[a]][key]++;
            }

            long long need = prefix[i] - 3LL*capacity[i];

            if(cnt.count(capacity[i])){
                auto &inner = cnt[capacity[i]];
                if(inner.count(need)) ans += inner[need];
            }
        }

        return ans;
    }
};
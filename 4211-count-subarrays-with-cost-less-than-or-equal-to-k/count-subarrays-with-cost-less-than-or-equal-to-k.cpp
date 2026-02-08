using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<ll> ms;
        ll ans = 0;
        int l = 0;

        for(int r = 0; r <(int)nums.size(); r++){
            ms.insert(nums[r]);

            while(l <= r){
                ll mn = *ms.begin();
                ll mx = *ms.rbegin();
                ll len = (r-l+1)*1LL;

                ll cost = (mx-mn) * len;

                if(cost <= k) break;

                auto it = ms.find(nums[l]);
                ms.erase(it);
                l++;
            }

            ans += (ll)(r-l+1);
        }
        return ans;
    }
};
class Solution {
public:
    int getMaxCapacity(int remaining, int i, vector<pair<int,int>>& arr2, vector<int>& prefix_max_capacity){
        if (i == 0) return 0;
        int lo = 0, hi = i-1;

        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(arr2[mid].first <= remaining){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }

        int idx;
        if (lo >= 0 && arr2[lo].first <= remaining) {
            idx = lo;        // all YES case
        } else {
            idx = lo - 1;    // first NO case
        }

        if (idx < 0) return 0; // no valid machines
        return prefix_max_capacity[idx];
    }
    
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(costs[i] < budget) ans = max(ans, capacity[i]);
        }

        vector<pair<int,int>> arr2;
        for(int i = 0; i < n; i++){
            int cst = costs[i];
            int cap = capacity[i];
            arr2.push_back({cst,cap});
        }

        sort(arr2.begin(), arr2.end());

        vector<int> prefix_max_capacity(n, arr2[0].second);
        for(int i = 1; i < n; i++){
            prefix_max_capacity[i] = max(prefix_max_capacity[i-1], arr2[i].second);
        }

        for(int i = 0; i < n; i++){
            int cst = arr2[i].first, cap = arr2[i].second;
            
            if(cst >= budget) continue;

            int rem = budget - cst - 1;

            if(rem < 0) continue;

            int x = getMaxCapacity(rem,i,arr2,prefix_max_capacity);

            ans = max(ans, cap+x);
        }

        return ans;
    }
};
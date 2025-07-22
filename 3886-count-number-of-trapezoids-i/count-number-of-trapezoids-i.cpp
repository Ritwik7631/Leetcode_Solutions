class Solution {
public:
    long long mod = 1e9+7;

    long long inv2 = (mod + 1) / 2;

    long long combination(int &n){
        // n*(n-1)/2 % mod
        return ( (1LL * n * (n - 1) / 2) % mod );
    }
    
    int countTrapezoids(vector<vector<int>>& points) {
        // map key (y-value) : array of points with that same y value
        unordered_map<int, vector<vector<int>>> mp;

        for(auto a : points){
            mp[a[1]].push_back(a);
        }

        vector<long long> combos;

        int total = 0;

        for(auto a : mp){
            if(a.second.size() > 1){
                int s = a.second.size();
                int c = combination(s);
                total += c;
                combos.push_back(c);
            }
        }

        // long long ans = 0;

        // for(int i = 0; i < combos.size(); i++){
        //     for(int j = i+1; j < combos.size(); j++){
        //         ans = ans + ((combos[i] % mod * combos[j] % mod) % mod);
        //     }
        // }

        // return int(ans % mod);

        // ─── REPLACE THE NESTED LOOPS WITH THIS ## COMPLICATD ## ───
        // long long S = 0, sumSq = 0;
        // for(long long c : combos) {
        //     c %= mod;
        //     S = (S + c) % mod;
        //     sumSq = (sumSq + c * c % mod) % mod;
        // }
        // long long inv2 = (mod + 1) / 2;
        // long long ans = ((S * S % mod - sumSq + mod) % mod) * inv2 % mod;
        // ──────────────────────────────────────────

        long long ans = 0;

        for(long long c : combos){
            long long other = (total - c) % mod;
            ans = (ans + c % mod * other % mod) % mod;
        }

        ans = ans * inv2 % mod;
        return ans;
    }
};
class Solution {
public:
    long long gcdll(long long a, long long b){
        while (b) { long long t = a % b; a = b; b = t; }
        return a;
    }

    long long lcm(long long a, long long b){
        return (a / gcdll(a, b)) * b;
    }

    bool valid(long long t, vector<int>& d, vector<int>& r){
        if((t - (t/r[0]) >= d[0]) && (t - (t/r[1]) >= d[1]) && (t - (t/lcm((long long)r[0], (long long)r[1]))) >= (d[0] + d[1])) return true;

        return false;
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long hi = (long long)(d[0] + d[1]) * max(r[0], r[1]);
        long long lo = 0;

        while(lo < hi){
            long long mid = lo + (hi - lo)/2LL;

            if(valid(mid, d, r)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        return hi;
    }
};
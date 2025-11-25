class Solution {
public:
    long long dp[20][2][2];
    long long solve(int idx, string str, bool constrained, bool began){
        if(idx == str.size()){
            if(began) return 1;
            else return 0;
        }

        if(dp[idx][constrained][began] != -1) return dp[idx][constrained][began]; 

        long long ans = 0;

        int mxdigit = str[idx] - '0';
        int mxallowed = (constrained) ? mxdigit : 9;

        if(!began){
            bool nc = constrained && mxallowed == 0;
            ans += solve(idx+1, str, nc, false);
        }
        

        for(int d = 1; d <= 9; d++){
            if(d > mxallowed) break;

            bool nc = constrained && (mxallowed == d);

            ans += solve(idx+1, str, nc, true);
        }

        return dp[idx][constrained][began] = ans;
    }

    long long countDistinct(long long n) {
        string str = to_string(n);

        memset(dp, -1, sizeof(dp));

        return solve(0,str,true,false);
    }
};
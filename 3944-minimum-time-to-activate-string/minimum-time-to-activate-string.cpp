class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        // s = "r i t w i k"
        // order = [5 1 2 0 4 3]
        // t = 0
        // order[t] = order[0] = 5
        // s = "r i t w i *" -> considered valid because it has at least 1 *
        // string is active if # of substrings that are valid >= k at time t

        // ok so the problem I need to solve is how to check valid substrings efficiently
        // my string can be of length 1e5 so I cannot do a brute force substring calculation at every t in the worst case. The brute force substring calculation has a tc: O(n^2)

        // so let's say I have a string t = whatever where 
        // e: string s = "a*c**dgergerg*f*sfsfsfsf**f"
        // 0: string s = "abcdedgergergffhsfsfsfsfhi"
        // 1: string s = "a*cdedgergergffhsfsfsfsfhi" current valid substrings = # start * # end = 2 * (26-2+1) = 50
        // 2: string s = "a*c*edgergergffhsfsfsfsfhi" current valid substrings = 50 + 2*(26-4+1) = 50 + 46 = 96
        // 3: string s = "a*c**dgergergffhsfsfsfsfhi" current valid substrings = 96 + 1*(26-5+1) = 96 + 22 = 118

        int n = s.size();

        int t = -1;

        long long cvs = 0;

        set<int> stars = {-1, n};

        for(int i = 0; i < order.size(); i++){
            t++;
            int ind = order[t];

            auto it_right = stars.upper_bound(ind);
            auto it_left = prev(it_right);

            int p = *it_right;
            int q = *it_left;

            cvs += 1LL * (ind - p) * (q - ind);

            stars.insert(ind);

            if(cvs >= k) return t;
        }

        return -1;
    }
 };
class Solution {
public:
    struct SegTree{
        int n;
        vector<long long> seg, lz;
        SegTree(int n): n(n), seg(4*n, 0), lz(4*n, 0) {}
        
        inline int left(int p) { return 2*p; }
        inline int right(int p) {return 2*p+1; }

        void push(int p, int l, int r){
            if(lz[p] == 0 || l == r) return;
            int m = (l+r)/2;
            int lc = left(p);
            int rc = right(p);
            long long v = lz[p];
            seg[lc] += v * (m-l+1); lz[lc] += v;
            seg[rc] += v * (r-m);   lz[rc] += v;
            lz[p] = 0;
        }

        void add(int p, int l, int r, int ql, int qr, long long v){
            if(qr < l || r < ql) return;
            if(ql <= l && r <= qr){
                seg[p] += v * (r-l+1);
                lz[p] += v;
                return;
            }
            push(p, l, r);
            int m = (l+r)/2;
            add(left(p), l, m, ql, qr, v);
            add(right(p), m+1, r, ql, qr, v);
            seg[p] = seg[left(p)] + seg[right(p)];
        }

        long long sum(int p, int l, int r, int ql, int qr){
            if(qr < l || r < ql) return 0;
            if(ql <= l && r <= qr) return seg[p];
            push(p, l, r);
            int m = (l+r) / 2;
            return sum(left(p), l, m, ql, qr) + sum(right(p), m+1, r, ql, qr);
        }
    };

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        SegTree st(n);
        for(auto b : bookings){
            int l = b[0] - 1;
            int r = b[1] - 1;
            int v = b[2];
            st.add(1, 0, n-1, l, r, v);
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = st.sum(1, 0, n-1, i, i);
        }
        return ans;
    }
};
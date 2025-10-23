class Solution {
public:
    struct SegTree{
        int n;
        vector<long long> seg, lz, mn, mx;      // add mn/mx to detect zeros
        SegTree(int n): n(n), seg(4*n, 0), lz(4*n, 0), mn(4*n, 0), mx(4*n, 0) {}
        
        inline int left(int p)  { return 2*p; }
        inline int right(int p) { return 2*p+1; }

        void push(int p, int l, int r){
            if(lz[p] == 0 || l == r) return;
            int m = (l+r)/2;
            int lc = left(p), rc = right(p);
            long long v = lz[p];
            seg[lc] += v * (m - l + 1); lz[lc] += v; mn[lc] += v; mx[lc] += v;
            seg[rc] += v * (r - m);     lz[rc] += v; mn[rc] += v; mx[rc] += v;
            lz[p] = 0;
        }

        void pull(int p){
            seg[p] = seg[left(p)] + seg[right(p)];
            mn[p]  = std::min(mn[left(p)], mn[right(p)]);
            mx[p]  = std::max(mx[left(p)], mx[right(p)]);
        }

        void add(int p, int l, int r, int ql, int qr, long long v){
            if(qr < l || r < ql) return;
            if(ql <= l && r <= qr){
                seg[p] += v * (r - l + 1);
                lz[p]  += v;
                mn[p]  += v;
                mx[p]  += v;
                return;
            }
            push(p, l, r);
            int m = (l+r)/2;
            add(left(p),  l,   m, ql, qr, v);
            add(right(p), m+1, r, ql, qr, v);
            pull(p);
        }

        long long sum(int p, int l, int r, int ql, int qr){
            if(qr < l || r < ql) return 0;
            if(ql <= l && r <= qr) return seg[p];
            push(p, l, r);
            int m = (l+r) / 2;
            return sum(left(p), l, m, ql, qr) + sum(right(p), m+1, r, ql, qr);
        }

        // first index in [ql,qr] whose value == 0; -1 if none
        int first_zero(int p, int l, int r, int ql, int qr){
            if(qr < l || r < ql) return -1;
            if(mn[p] > 0 || mx[p] < 0) return -1; // no zero possible here
            if(l == r) return l;
            push(p, l, r);
            int m = (l+r)/2;
            int leftAns = first_zero(left(p), l, m, ql, qr);
            if(leftAns != -1) return leftAns;
            return first_zero(right(p), m+1, r, ql, qr);
        }
    };

    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        SegTree st(n);
        unordered_map<int,int> last; // last index seen for value
        int ans = 0;

        for(int i = 0; i < n; i++){
            int parity = (nums[i] % 2 == 0) ? +1 : -1;
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            // add parity to all F[L] for L in [0..i]
            st.add(1, 0, n-1, 0, i, parity);
            // if duplicate, cancel its contribution for L <= prev
            if(prev != -1) st.add(1, 0, n-1, 0, prev, -parity);

            // find first L in [0..i] with F[L] == 0
            int L = st.first_zero(1, 0, n-1, 0, i);
            if(L != -1) ans = max(ans, i - L + 1);

            last[nums[i]] = i;
        }
        return ans;
    }
};

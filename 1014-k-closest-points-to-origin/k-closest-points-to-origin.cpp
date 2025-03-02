class Solution {
public:
    struct Closest {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const{
            double d1 = sqrt(a.first * a.first + a.second * a.second);
            double d2 = sqrt(b.first * b.first + b.second * b.second);
            return d1 < d2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> prs;
        for (auto a : points) {
            prs.push_back({a[0], a[1]});
        }

        multiset<pair<int,int>, Closest> ms(prs.begin(), prs.end());

        while (ms.size() > k) {
            auto it = prev(ms.end());
            ms.erase(it);
        }

        vector<vector<int>> ans;
        for (auto p : ms) {
            ans.push_back({p.first, p.second});
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int y1, y2, px;
    bool operator<(const Interval &other) const {
        // Sort primarily by y1, then by y2, then by px
        if (y1 != other.y1) return y1 < other.y1;
        if (y2 != other.y2) return y2 < other.y2;
        return px < other.px;
    }
};

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        // INF large enough for no overlap
        const long long INF = 100000000000000000LL;

        int n = (int)xCoord.size();
        // points[x] = vector of all y at this x
        map<int, vector<int>> points;
        for (int i = 0; i < n; i++) {
            points[xCoord[i]].push_back(yCoord[i]);
        }
        for (auto &kv : points) {
            sort(kv.second.begin(), kv.second.end());
        }

        // sl will store intervals (y1,y2,px)
        // px is the x where the interval was added
        set<Interval> sl;
        long long max_area = -1;

        vector<int> xs;
        for (auto &kv : points) xs.push_back(kv.first);
        sort(xs.begin(), xs.end());

        for (auto x : xs) {
            // Remove invalid intervals
            // We'll store intervals to remove
            vector<Interval> toRemove;

            // Check for rectangles using existing intervals
            // For each pair (y1, y2) in points[x], try to find a matching interval in sl
            auto &Y = points[x];
            for (int i = 0; i + 1 < (int)Y.size(); i++) {
                int y1 = Y[i], y2 = Y[i+1];

                // Try to find (y1,y2) in sl
                // We do a lower_bound with something that will position us around (y1,y2)
                Interval query{y1, y2, (int)-INF};
                auto it = sl.lower_bound(query);
                // Check it and it-1 for a match
                if (it != sl.end() && it->y1 == y1 && it->y2 == y2) {
                    // Found exact interval
                    long long px = it->px;
                    long long area = (long long)(y2 - y1)*(x - px);
                    if (area > max_area) max_area = area;
                } else if (it != sl.begin()) {
                    auto prevIt = prev(it);
                    if (prevIt->y1 == y1 && prevIt->y2 == y2) {
                        long long px = prevIt->px;
                        long long area = (long long)(y2 - y1)*(x - px);
                        if (area > max_area) max_area = area;
                    }
                }
            }

            // Now remove intervals invalidated by points on this line
            for (auto y : Y) {
                // We want to find intervals that may contain y
                // We'll search by (y, -1, -INF) to find position around intervals starting at or before y
                Interval query{y, -1, (int)-INF};
                auto it = sl.lower_bound(query);

                // Check intervals before it
                {
                    // Make a copy iterator for backward search
                    auto bit = it;
                    while (bit != sl.begin()) {
                        auto pit = prev(bit);
                        if (pit->y1 <= y && pit->y2 >= y) {
                            toRemove.push_back(*pit);
                            bit = pit;
                            if (bit == sl.begin()) break;
                        } else {
                            break;
                        }
                    }
                }

                // Check the interval at it if any
                if (it != sl.end()) {
                    if (it->y1 <= y && it->y2 >= y) {
                        toRemove.push_back(*it);
                    }
                }
            }

            // Remove all invalid intervals
            for (auto &rem : toRemove) {
                sl.erase(rem);
            }

            // Add new intervals from this line
            for (int i = 0; i + 1 < (int)Y.size(); i++) {
                int y1 = Y[i], y2 = Y[i+1];
                sl.insert({y1, y2, x});
            }
        }

        return max_area;
    }
};
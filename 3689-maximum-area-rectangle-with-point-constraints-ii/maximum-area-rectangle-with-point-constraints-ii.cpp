#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        // Define the tuple as (y1, y2, px)
        // This ordering ensures that the set sorts primarily by y1, then y2, then px
        set<tuple<int, int, int>> sl;
        long long max_area = -1;

        int n = xCoord.size();
        // Map to store y-coordinates for each x-coordinate
        map<int, vector<int>> points;
        for (int i = 0; i < n; i++) {
            points[xCoord[i]].push_back(yCoord[i]);
        }
        // Sort the y-coordinates for each x-coordinate
        for (auto &kv : points) {
            sort(kv.second.begin(), kv.second.end());
        }

        // Extract and sort all unique x-coordinates
        vector<int> xs;
        for (auto &kv : points) xs.push_back(kv.first);
        sort(xs.begin(), xs.end());

        for (auto x : xs) {
            // Current y-coordinates at this x
            auto &Y = points[x];
            // Vector to store intervals that need to be removed
            vector<tuple<int, int, int>> toRemove;

            // Check for possible rectangles with existing intervals
            for (int i = 0; i + 1 < (int)Y.size(); i++) {
                int y1 = Y[i], y2 = Y[i+1];
                // Create a query tuple with px as INT32_MIN to find the lower bound
                tuple<int, int, int> query = make_tuple(y1, y2, INT32_MIN);
                auto it = sl.lower_bound(query);
                // Check if the current (y1, y2) exists in the set
                if (it != sl.end() && get<0>(*it) == y1 && get<1>(*it) == y2) {
                    // Found an exact interval
                    long long px = get<2>(*it);
                    long long area = (long long)(y2 - y1) * (x - px);
                    max_area = max(max_area, area);
                } 
                // Also check the previous iterator in case of multiple intervals with same y1 and y2
                else if (it != sl.begin()) {
                    auto prevIt = prev(it);
                    if (get<0>(*prevIt) == y1 && get<1>(*prevIt) == y2) {
                        long long px = get<2>(*prevIt);
                        long long area = (long long)(y2 - y1) * (x - px);
                        max_area = max(max_area, area);
                    }
                }
            }

            // Now remove intervals invalidated by points on this x-line
            for (auto y : Y) {
                // Define a query to find intervals that might contain y
                // Since tuples are sorted, we can perform a lower_bound search
                tuple<int, int, int> query = make_tuple(y, -1, INT32_MIN);
                auto it = sl.lower_bound(query);

                // Check intervals before 'it'
                if (it != sl.begin()) {
                    auto bit = prev(it);
                    while (true) {
                        if (get<0>(*bit) <= y && get<1>(*bit) >= y) {
                            toRemove.push_back(*bit);
                            if (bit == sl.begin()) break;
                            bit = prev(bit);
                        } else {
                            break;
                        }
                    }
                }

                // Check the interval at 'it' if it exists
                if (it != sl.end()) {
                    if (get<0>(*it) <= y && get<1>(*it) >= y) {
                        toRemove.push_back(*it);
                    }
                }
            }

            // Remove all invalidated intervals
            for (auto &rem : toRemove) {
                sl.erase(rem);
            }

            // Add new intervals from this line
            for (int i = 0; i + 1 < (int)Y.size(); i++) {
                int y1 = Y[i], y2 = Y[i+1];
                sl.emplace(y1, y2, x);
            }
        }

        return max_area;
    }
};

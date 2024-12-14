class Solution {
public:
    long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
        int n = xCoord.size();

        map<int, vector<int>> ys_in_x;
        vector<vector<int>> prs;

        for (int i = 0; i < n; i++) {
            prs.push_back({xCoord[i], yCoord[i]});
        }

        for (int i = 0; i < n; i++) {
            ys_in_x[prs[i][0]].push_back(prs[i][1]);
        }

        for (auto& a : ys_in_x) {  // Use reference to modify `a.second`
            sort(a.second.begin(), a.second.end());
        }

        map<pair<int, int>, int> candidates;
        long long max_area = -1;  // Use `long long` to avoid overflow

        for (auto& a : ys_in_x) {
            // vector<pair<int, int>> segments;
            set<pair<int,int>> remove;
            // for (int i = 1; i < a.second.size(); i++) {
            //     segments.push_back({a.second[i - 1], a.second[i]});
            // }

            for (int i = 1; i < a.second.size(); i++) {
                pair<int,int> pr = {a.second[i-1], a.second[i]};
                if (candidates.find(pr) != candidates.end()) {
                    int prev_x = candidates[pr];
                    long long area = 1LL * abs(a.first - prev_x) * abs(pr.second - pr.first);
                    max_area = max(max_area, area);
                }

                candidates[pr] = a.first;
                
            }

            for (auto& y : ys_in_x[a.first]) {
                auto it = candidates.lower_bound(make_pair(y, -1));

                if(it != candidates.end())
                {                    
                    if(y >= it->first.first && y <= it->first.second && it->second != a.first)
                    {
                        remove.insert(it->first);
                    }
                }

                if(it != candidates.begin())
                {
                    it = prev(it);
                    while(y >= it->first.first && y <= it->first.second)
                    {
                        if(it->second != a.first)
                        {
                            remove.insert(it->first);
                        }

                        if(it == candidates.begin())
                        {
                            break;
                        }
                        it = prev(it);
                    }
                }

                for(auto te : remove)
                {
                    candidates.erase(te);
                }

            }
        }

        return max_area;
    }
};

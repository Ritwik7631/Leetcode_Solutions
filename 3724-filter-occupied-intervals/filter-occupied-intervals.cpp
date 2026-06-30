class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& OI, int freeStart, int freeEnd) {
        int n = OI.size();

        sort(OI.begin(), OI.end());

        // for(auto c : OI){
        //     cout << "[" << c[0] << ", " << c[1] << "]";
        //     cout << endl;
        // }

        vector<vector<int>> merged_oi;
        
        for(int i = 0; i < n; i++){
            if(i == 0){
                merged_oi.push_back(OI[i]);
                continue;
            }

            if((OI[i][0] >= merged_oi.back()[0] && OI[i][0] <= merged_oi.back()[1]) ||
               (OI[i][1] >= merged_oi.back()[0] && OI[i][1] <= merged_oi.back()[1]) ||
               (OI[i][0] - 1 == merged_oi.back()[1])) {
                int cs = merged_oi.back()[0], ce = merged_oi.back()[1];
                merged_oi.pop_back();

                if(OI[i][0] - 1 == ce) ce = OI[i][1];
                else{
                    cs = min(OI[i][0], cs);
                    ce = max(OI[i][1], ce);
                }

                merged_oi.push_back({cs, ce});
               }
            else{
                merged_oi.push_back(OI[i]);
            }
        }

        for(auto c : merged_oi){
            cout << "[" << c[0] << ", " << c[1] << "]";
            cout << endl;
        }

        n = merged_oi.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            int s = merged_oi[i][0];
            int e = merged_oi[i][1];

            // No overlap with free interval
            if (e < freeStart || s > freeEnd) {
                ans.push_back({s, e});
            } 
            else {
                // Left remaining part
                if (s < freeStart) {
                    ans.push_back({s, freeStart - 1});
                }

                // Right remaining part
                if (e > freeEnd) {
                    ans.push_back({freeEnd + 1, e});
                }
            }
        }

        return ans;
    }
};
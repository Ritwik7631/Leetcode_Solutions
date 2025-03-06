class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        for(int r = 1; r < n; r++)
        {
            if(intervals[r][0] <= curr[1])
            {
                curr[1] = max(curr[1],intervals[r][1]);
            }
            else
            {
                ans.push_back(curr);
                curr = intervals[r];
            }
        }

        ans.push_back(curr);

        return ans;
    }
};
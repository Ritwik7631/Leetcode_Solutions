class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        
        int a = intervals[0][0];
        int b = intervals[0][1];

        vector<vector<int>> ans;

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= b)
            {
                b = max(b, intervals[i][1]);
            }
            else
            {
                ans.push_back({a,b});

                a = intervals[i][0];
                b = intervals[i][1];
            }
        }

        ans.push_back({a,b});

        return ans;
    }
};
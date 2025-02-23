class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        // index, height
        int n = heights.size();

        int ans = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            int s = i;
            while(!stk.empty() && heights[i] < stk.top().second)
            {
                s = stk.top().first;
                int w = i - s;
                int h = stk.top().second;

                ans = max(ans, w*h);

                stk.pop();
            }

            stk.push({s, heights[i]});
        }

        while(!stk.empty())
        {
            ans = max(ans, (n - stk.top().first) * stk.top().second);
            stk.pop();
        }

        return ans;
    }
};
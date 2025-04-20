class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;

        stack<int> stk;

        int n = heights.size();

        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && heights[i] < heights[stk.top()])
            {
                int height = heights[stk.top()];
                stk.pop();

                int width;

                if(stk.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - stk.top() - 1;
                }

                ans = max(ans, height * width);
            }

            stk.push(i);
        }

        while(!stk.empty())
        {
            int height = heights[stk.top()];
            stk.pop();

            int width;

            if(stk.empty())
            {
                width = n;
            }
            else
            {
                width = n - 1 - stk.top();
            }

            ans = max(ans, height * width);
    }

        return ans;
    }
};
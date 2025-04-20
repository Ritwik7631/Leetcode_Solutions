#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        the idea is to use a stack to store the index of the heights in the histogram. The stack is monotonically increasing. Then we take the minimum of the monotonically
        increasing stack and that is our height and then we see how many bars contribute to the width
        */

       int n = heights.size();
       stack<int> stk;
       int mx = 0;
       for(int i = 0; i < n; i++)
       {
            while(!stk.empty() && heights[i] < heights[stk.top()])
            {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1; // if stk is empty then the width is the current index else the width is the current index - the index of the top of the stack
                mx = max(mx, height * width);
            }
            stk.push(i);
       }

       while(!stk.empty())
       {
        int height = heights[stk.top()];
        stk.pop();
        int width = stk.empty() ? n : n - stk.top() - 1;
        mx = max(mx, height * width);
       }
       return mx;
    }
};
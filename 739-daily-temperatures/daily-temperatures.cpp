class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n);

        stack<pair<int,int>> stk;

        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty())
            {
                if(stk.top().first > temperatures[i])
                {
                    ans[i] = stk.top().second - i;
                    break;
                }
                else
                {
                    stk.pop();
                }
            }

            stk.push({temperatures[i], i});
        }

        return ans;
    }
};
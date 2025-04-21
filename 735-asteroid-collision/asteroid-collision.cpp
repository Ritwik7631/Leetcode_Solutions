#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        int n = asteroids.size();

        for(int i = 0; i < n; i++)
        {
            bool destroyed = false;

            while(!stk.empty() && asteroids[i] < 0 && stk.top() > 0)
            {
                if(abs(stk.top()) < abs(asteroids[i])) // left asteroid is bigger than right asteroid on top of stack
                {
                    stk.pop();
                    continue;
                }
                else if(abs(stk.top()) == abs(asteroids[i])) // same size opposite directions
                {
                    stk.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) stk.push(asteroids[i]);
        }

        vector<int> ans;

        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;      
    }
};
class Solution {
public:
    bool willmeet(pair<int,int> &current, pair<int,int> &ahead, int &target)
    {
        double x = static_cast<double>(target - current.first) / current.second;
        double y = static_cast<double>(target - ahead.first) / ahead.second;

        return y >= x;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> ps(n);

        for(int i = 0; i < n; i++)
        {
            ps[i] = make_pair(position[i], speed[i]);
        }

        sort(ps.begin(), ps.end());

        stack<pair<int,int>> stk;

        for(int i = n-1; i >= 0; i--)
        {
            while(stk.empty() || !willmeet(ps[i], stk.top(), target))
            {
                stk.push(ps[i]);
            }
        }

        return stk.size();
    }
};
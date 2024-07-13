class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        set<pair<pair<int, int>, pair<char, int>>> st;
        // position, health, direction, robot number
        for (int i = 0; i < positions.size(); i++) {
            int a = positions[i];
            char b = directions[i];
            int h = healths[i];
            int num = i;
            st.insert({{a, h}, {b, num}});
        }

        stack<pair<pair<int, int>, pair<char, int>>> stk;

        while (!st.empty()) {
            auto it = st.begin();
            pair<pair<int, int>, pair<char, int>> pr = *it;
            int pos = pr.first.first;
            int heal = pr.first.second;
            char dir = pr.second.first;
            int robonum = pr.second.second;
            st.erase(it);

            while (!stk.empty() && (dir == 'L' && stk.top().second.first == 'R')) {
                if (heal == stk.top().first.second) {
                    stk.pop();
                    heal = -1; // Both robots are destroyed
                    break;
                } else if (heal < stk.top().first.second) {
                    auto top = stk.top();
                    stk.pop();
                    top.first.second--;
                    stk.push(top);
                    heal = -1; // Current robot is destroyed
                    break;
                } else {
                    stk.pop();
                    heal--;
                }
            }

            if (heal > 0) {
                stk.push({{pos, heal}, {dir, robonum}});
            }
        }

        vector<int> ans(positions.size(), -1);

        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            ans[top.second.second] = top.first.second;
        }

        // Remove -1 entries
        vector<int> result;
        for (int h : ans) {
            if (h != -1) {
                result.push_back(h);
            }
        }

        return result;
    }
};

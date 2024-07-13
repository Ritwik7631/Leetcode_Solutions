class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Reorder inputs by position
        set<pair<pair<int, int>, pair<char, int>>> st;
        // position, health, direction, robot number
        for (int i = 1; i <= positions.size(); i++) {
            int a = positions[i-1];
            char b = directions[i-1];
            int h = healths[i-1];
            int num = i - 1; // Corrected to use 0-based indexing for robot number
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
                    stk.pop(); // Both robots are destroyed
                    heal = -1; // Mark this robot as destroyed
                    break;
                } else if (heal < stk.top().first.second) {
                    auto top = stk.top();
                    stk.pop();
                    top.first.second--; // Reduce health of the top robot
                    stk.push(top);
                    heal = -1; // Current robot is destroyed
                    break;
                } else {
                    stk.pop();
                    heal--; // Current robot survives but loses 1 health
                }
            }

            if (heal > 0) {
                stk.push({{pos, heal}, {dir, robonum}});
            }
        }

        // Collect the results in the original order
        vector<int> ans(positions.size(), -1);
        while (!stk.empty()) {
            auto top = stk.top();
            stk.pop();
            ans[top.second.second] = top.first.second; // Place health in original order
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

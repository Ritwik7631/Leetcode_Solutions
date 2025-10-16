class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        int n = c.size();
        if (n <= 2) return true;

        int x0 = c[0][0], y0 = c[0][1];
        int dx = c[1][0] - x0;
        int dy = c[1][1] - y0;

        for (int i = 2; i < n; i++) {
            int x = c[i][0], y = c[i][1];
            if ((x - x0) * dy != (y - y0) * dx) return false;
        }
        return true;
    }
};

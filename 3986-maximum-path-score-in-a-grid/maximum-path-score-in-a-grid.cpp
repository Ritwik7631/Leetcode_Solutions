class Solution {
public:
    int n, m;
    vector<vector<int>> *G;

    static constexpr int UNVIS = -2; // not computed
    static constexpr int IMP   = -1; // computed impossible

    vector<vector<vector<int>>> memo;

    inline int cost(int v) { return v == 0 ? 0 : 1; }

    int dfs(int i, int j, int rem) {
        int v = (*G)[i][j];
        int rem2 = rem - cost(v);
        if (rem2 < 0) return IMP;

        if (memo[i][j][rem] != UNVIS) return memo[i][j][rem];

        if (i == n-1 && j == m-1)
            return memo[i][j][rem] = v;

        int best = IMP;
        if (i + 1 < n) {
            int down = dfs(i + 1, j, rem2);
            if (down != IMP) best = max(best, down);
        }
        if (j + 1 < m) {
            int right = dfs(i, j + 1, rem2);
            if (right != IMP) best = max(best, right);
        }

        if (best == IMP) return memo[i][j][rem] = IMP;
        return memo[i][j][rem] = v + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size(); m = grid[0].size(); G = &grid;
        memo.assign(n, vector<vector<int>>(m, vector<int>(k + 1, UNVIS)));
        int ans = dfs(0, 0, k);
        return ans == IMP ? -1 : ans;
    }
};

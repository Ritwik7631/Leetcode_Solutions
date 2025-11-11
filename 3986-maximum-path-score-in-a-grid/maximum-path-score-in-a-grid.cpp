class Solution {
public:
    static constexpr int UNVIS = -2;
    static constexpr int IMP = -1;

    int n, m;
    vector<vector<int>> *G;
    vector<vector<vector<int>>> memo;

    int cost(int v){
        return v == 0 ? 0 : 1;
    }

    int dfs(int i, int j, int rem){
        
        if(memo[i][j][rem] != UNVIS) return memo[i][j][rem];

        if(i == n-1 && j == m-1) return memo[i][j][rem] = 0;

        int best = IMP;
        if (i + 1 < n) {
            int w = cost((*G)[i + 1][j]);
            if (rem >= w) {
                int down = dfs(i + 1, j, rem - w);
                if (down != IMP) {
                    int cand = (*G)[i + 1][j] + down;
                    if (cand > best) best = cand;
                }
            }
        }

        if (j + 1 < m) {
            int w = cost((*G)[i][j + 1]);
            if (rem >= w) {
                int right = dfs(i, j + 1, rem - w);
                if (right != IMP) {
                    int cand = (*G)[i][j + 1] + right;
                    if (cand > best) best = cand;
                }
            }
        }

        return memo[i][j][rem] = best;
    }


    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        G = &grid;
        memo.assign(n, vector<vector<int>> (m, vector<int> (k+1, UNVIS)));

        int ans = dfs(0,0,k);
        
        if(ans == IMP) return -1;

        return grid[0][0] + ans;

    }
};
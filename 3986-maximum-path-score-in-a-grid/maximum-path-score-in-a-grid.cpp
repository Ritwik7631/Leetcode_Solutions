class Solution {
public:
    int fn(int x){
        return x == 0 ? 0 : 1; // cost: 1 if 1 or 2, else 0
    }

    // memo[i][j][cost] = best additional score achievable from (i,j) with 'cost' already spent
    // UNSET = INT_MIN, IMPOSSIBLE = -1e9
    vector<vector<vector<int>>> memo;
    static constexpr int IMPOSSIBLE = -1000000000;

    int dfs(int i, int j, int score, int cost, int n, int m, int k,
            vector<vector<int>>& visited, vector<vector<int>>& grid){
        if(i == n-1 && j == m-1) return score;

        int &cell = memo[i][j][cost];
        if (cell != INT_MIN) {
            if (cell == IMPOSSIBLE) return INT_MIN;
            return score + cell; // reuse cached "extra" part
        }

        int right = INT_MIN, down = INT_MIN;

        // right
        int ni = i, nj = j+1;
        if(nj < m && !visited[ni][nj]){
            int x = fn(grid[ni][nj]);
            int n_cost = cost + x;
            if(n_cost <= k){
                visited[ni][nj] = 1;
                right = max(right, dfs(ni, nj, score + grid[ni][nj], n_cost, n, m, k, visited, grid));
                visited[ni][nj] = 0;
            }
        }

        // down
        ni = i+1; nj = j;
        if(ni < n && !visited[ni][nj]){
            int x = fn(grid[ni][nj]);
            int n_cost = cost + x;
            if(n_cost <= k){
                visited[ni][nj] = 1;
                down = max(down, dfs(ni, nj, score + grid[ni][nj], n_cost, n, m, k, visited, grid));
                visited[ni][nj] = 0;
            }
        }

        int best = max(right, down);
        if (best == INT_MIN) {
            cell = IMPOSSIBLE;
            return INT_MIN;
        }
        cell = best - score;           // store "additional" score from this state
        return best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;

        memo.assign(n, vector<vector<int>>(m, vector<int>(k+1, INT_MIN)));

        int ans = dfs(0, 0, grid[0][0], 0, n, m, k, visited, grid);
        return ans == INT_MIN ? -1 : ans;
    }
};

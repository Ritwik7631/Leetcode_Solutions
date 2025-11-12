class Solution {
public:
    vector<vector<vector<int>>> memo;
    vector<vector<int>> *G;

    int UNVIS = -1;
    int IMP = -2;

    int n,m;

    int cost(int x){
        return (x == 0) ? 0 : 1;
    }

    int dfs(int i, int j, int rem){
        if(i == n-1 && j == m-1) return (*G)[i][j];

        if(memo[i][j][rem] != UNVIS) return memo[i][j][rem];

        int best = IMP;

        // down
        if(i+1 < n){
            int c = cost((*G)[i+1][j]);
            if(rem - c >= 0){
                int down = dfs(i+1, j, rem - c);
                if(down != IMP) best = max(best, (*G)[i][j] + down);
            }
        }

        if(j+1 < m){
            int c = cost((*G)[i][j+1]);
            if(rem - c >= 0){
                int right = dfs(i, j+1, rem-c);
                if(right != IMP) best = max(best, (*G)[i][j] + right);
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

        return ans == IMP ? -1 : ans;
    }
};
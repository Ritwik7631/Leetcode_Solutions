class Solution {
public:
    vector<vector<string>> ans;
    set<int> col;
    set<int> positive_diag;
    set<int> negative_diag;

    void dfs(int r, int n, vector<string>& board)
    {
        if(r == n)
        {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++)
        {
            if(col.count(c) || positive_diag.count(r+c) || negative_diag.count(r-c)) continue;

            board[r][c] = 'Q';
            col.insert(c);
            positive_diag.insert(r+c);
            negative_diag.insert(r-c);

            dfs(r+1, n, board);

            board[r][c] = '.';
            col.erase(c);
            positive_diag.erase(r+c);
            negative_diag.erase(r-c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(0, n, board);

        return ans;
    }
};
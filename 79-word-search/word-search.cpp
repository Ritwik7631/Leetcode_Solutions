class Solution {
public:
    vector<int> rdel{1, 0, -1, 0};
    vector<int> cdel{0, -1, 0, 1};

    bool dfs(int current_cell, int count, vector<vector<char>>& board, string word, vector<vector<int>>& vis)
    {
        if(count == word.size() - 1) return true;

        int r = current_cell/board[0].size();
        int c = current_cell%board[0].size();

        vis[r][c] = 1;

        for(int d = 0; d < 4; d++)
        {
            int nr = r + rdel[d];
            int nc = c + cdel[d];
            int next_cell = nr*board[0].size() + nc;

            if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] == word[count+1] && vis[nr][nc] == 0)
            {
                if(dfs(next_cell, count+1, board, word, vis)) return true;
                vis[nr][nc] = 0;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int start = 0; start < n*m; start++)
        {
            if(board[start/m][start%m] == word[0])
            {
                int count = 0;
                vector<vector<int>> vis(n, vector<int> (m, 0));
                if(dfs(start, count, board, word, vis)) return true;
            }
        }

        return false;
    }
};
class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visited;
    vector<int> rdel = {1, 0, -1, 0};
    vector<int> cdel = {0, -1, 0, 1};

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == word[0]) {
                    visited[r][c] = true;
                    if (dfs(board, word, r, c, 1))
                        return true;
                    visited[r][c] = false;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, const string &word, int r, int c, int idx) {
        if (idx == word.size())
            return true;

        for (int d = 0; d < 4; d++) {
            int nr = r + rdel[d];
            int nc = c + cdel[d];

            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                visited[nr][nc] == false && board[nr][nc] == word[idx]) {

                visited[nr][nc] = true;
                if (dfs(board, word, nr, nc, idx + 1)) return true;
                visited[nr][nc] = false;  

            }
        }
        return false;
    }
};

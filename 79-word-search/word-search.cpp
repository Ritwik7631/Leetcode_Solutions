class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        unordered_map<char, int> boardFreq;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                boardFreq[board[i][j]]++;
            }
        }
        unordered_map<char, int> wordFreq;
        for (char c : word) {
            wordFreq[c]++;
        }
        for (auto& p : wordFreq) {
            if (boardFreq[p.first] < p.second)
                return false;
        }

        if (boardFreq[word[0]] > boardFreq[word[word.size()-1]])
            reverse(word.begin(), word.end());

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (dfs(i, j, board, word, visited, 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int i, int j, vector<vector<char>>& board, const string &word,
             vector<vector<bool>>& visited, int idx) {
        if (idx == word.size())
            return true;
        
        // Direction vectors for down, left, up, and right.
        vector<int> rdel{1, 0, -1, 0};
        vector<int> cdel{0, -1, 0, 1};
        
        for (int d = 0; d < 4; d++) {
            int nr = i + rdel[d], nc = j + cdel[d];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() &&
                !visited[nr][nc] && board[nr][nc] == word[idx]) {
                visited[nr][nc] = true;
                if (dfs(nr, nc, board, word, visited, idx + 1))
                    return true;
                visited[nr][nc] = false;  // Backtracking
            }
        }
        return false;
    }
};

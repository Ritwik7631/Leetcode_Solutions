class Solution {
public:
    vector<int> rdel{1,0,-1,0};
    vector<int> cdel{0,-1,0,1};

    bool dfs(vector<int> curr, vector<vector<char>>& board, string& word, string& temp, vector<vector<int>>& vis)
    {
        if (board[curr[0]][curr[1]] != word[temp.size()]) return false;

        vis[curr[0]][curr[1]] = 1;
        temp += board[curr[0]][curr[1]];

        if(temp == word) return true;

        for(int d = 0; d < 4; d++)
        {
            int nr = curr[0] + rdel[d];
            int nc = curr[1] + cdel[d];

            if(nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && vis[nr][nc] == -1)
            {
                if(dfs({nr,nc}, board, word, temp, vis) == true) return true;
            }
        }

        vis[curr[0]][curr[1]] = -1;
        temp.pop_back();

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                string temp = "";
                vector<vector<int>> vis(n, vector<int>(m, -1));
                if(dfs({i,j}, board, word, temp, vis)) return true;
            }
        }

        return false;
    }
};
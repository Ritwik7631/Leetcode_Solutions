class Solution {
public:
    bool CanPlace(int r, int c, int n, vector<string>& board)
    {

        for(int i = 0; i < n; i++)
        {
            if(board[i][c] == 'Q') return false;
        }

        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q') return false;
        }

        for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void fn(int r, int n, vector<string> &board, int& count)
    {
        if(r == n)
        {
            count++;
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(CanPlace(r, col, n, board))
            {
                board[r][col] = 'Q';
                fn(r+1, n, board, count);
                board[r][col] = '.';
            }
        }

        return;
    }

    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));



        fn(0, n, board, count);

        return count;
    }
};
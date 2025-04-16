class Solution {
public:


    bool CanPlace(int r, int c, int n, vector<string>& board)
    {

        for(int i = 0; i < n; i++)
        {
            if(board[i][c] == 'Q') return false;
        }

        for(int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 'Q') return false;
        }

        for(int i = r, j = c; i >= 0 && j < n; i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void fn(int r, int n, vector<string> &board, vector<vector<string>>& result)
    {
        if(r == n)
        {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(CanPlace(r, col, n, board))
            {
                board[r][col] = 'Q';
                fn(r+1, n, board, result);
                board[r][col] = '.';
            }
        }

        return;
    }


    vector<vector<string>> solveNQueens(int n) {    
        /*
        Ok my approach is going is to basically asking each cell whether it can be a queen or not if it is valid we will explore that tree
        and then backtrack after exploring

        if we are not able to place the queen then we will move on to the next cell and try to place a queen there
        */

       vector<vector<string>> result;
       vector<string> board(n, string(n, '.'));



       fn(0, n, board, result);

       return result;
    }
};
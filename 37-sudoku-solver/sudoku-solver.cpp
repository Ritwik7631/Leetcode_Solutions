class Solution {
public:
    bool isValid(int row, int col, int k, vector<vector<char>>& board)
    {
        // checking row
        for(int j = 0; j < 9; j++)
        {
            if(board[row][j] == k + '0') return false;
        }

        // checking col
        for(int i = 0; i < 9; i++)
        {
            if(board[i][col] == k + '0') return false;
        }

        // checking square

        int x = (row/3) * 3; // 0, 3, 6
        int y = (col/3) * 3; // 0, 3, 6

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[x + i][y + j] == k + '0') return false;
            }
        }

        return true;
    }

    bool fn(int row, int col, vector<vector<char>>& board)
    {
        if(row == 9) return true; 

        if(col == 9) return fn(row + 1, 0, board);

        if(board[row][col] != '.') return fn(row, col + 1, board);

        for(int k = 1; k <= 9; k++)
        {
            if(isValid(row, col, k, board))
            {
                board[row][col] = k + '0';
                if(fn(row, col+1, board)) return true; 
                board[row][col] = '.';
            }
        }

        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        bool x = fn(0, 0, board);

        return;
    }
};

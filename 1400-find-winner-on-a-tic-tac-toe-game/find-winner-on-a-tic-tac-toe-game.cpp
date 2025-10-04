class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int> (3, -1));

        bool flag = true; // true == 1 == X while false == O
        for(auto a : moves){
            int r = a[0];
            int c = a[1];
            board[r][c] = flag;
            flag = !flag;
        }

        // left diagonal
        bool all_same = true;
        for(int i = 0; i < 3; i++){
            if(board[i][i] != board[0][0]){
                all_same = false;
                break;
            }
        }

        if(all_same){
            if (all_same && board[0][0] != -1) {      // add this guard
                return board[0][0] ? "A" : "B";
            }
        }

        // right diagonal
        all_same = true;
        for(int i = 0; i < 3; i++){
            if(board[3 - i - 1][i] != board[2][0]){
                all_same = false;
                break;
            }
        }

        if (all_same && board[2][0] != -1) {      // add this guard
            return board[2][0] ? "A" : "B";
        }


        // checking column elements
        for(int i = 0; i < 3; i++){
            set<int> st;
            for(int j = 0; j < 3; j++){
                st.insert(board[i][j]);
            }

            if(st.size() == 1 && st.count(-1) == 0){
                if(board[i][0]) return "A";
                else if(board[i][0] == false) return "B";
            }
        }

        // checking row elements
        for(int j = 0; j < 3; j++){
            set<int> st;
            for(int i = 0; i < 3; i++){
                st.insert(board[i][j]);
            }

            if(st.size() == 1 && st.count(-1) == 0){
                if(board[0][j]) return "A";
                else if(board[0][j] == false) return "B";
            }
        }

        // if we have reached this point and 9 moves were played then it is draw

        if(moves.size() == 9) return "Draw";
        
        return "Pending";
    }
};
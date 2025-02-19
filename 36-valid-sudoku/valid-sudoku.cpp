class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9, m = 9;

        for(int i = 0; i < n; i++)
        {
            set<int> st;

            for(int j = 0; j < n; j++)
            {
                if(board[i][j] != '.')
                {
                    if(st.count(board[i][j]) != 0)
                    {
                        return false;
                    }

                    st.insert(board[i][j]);                     
                }
             
            }
        }


        for(int j = 0; j < m; j++)
        {
            set<int> st;

            for(int i = 0; i < n; i++)
            {
                if(board[i][j] != '.')
                {
                    if(st.count(board[i][j]) != 0)
                    {
                        return false;
                    }

                    st.insert(board[i][j]);                     
                }
            }
        }

        // cout << "square check" << endl;
        // int count = 0;

        for(int i = 0; i < n; i = i + 3)
        {
            for(int j = 0; j < m; j = j + 3)
            {
                int y0 = j + 3;
                int x0 = i + 3;

                int y = j;
                int x = i;

                // count++;

                set<int> st;

                for(int k = x; k < x0; k++)
                {
                    for(int w = y; w < y0; w++)
                    {
                        if(board[k][w] != '.')
                        {
                            if(st.count(board[k][w]) != 0)
                            {
                                return false;
                            }

                            st.insert(board[k][w]);
                        }
                    }
                } 
            }
        }

        // cout << "count: " << count << endl;

        // for(auto a : board)
        // {
        //     for(auto b : a) cout << b << " ";
        //     cout << endl;
        // }

        return true;


    }
};
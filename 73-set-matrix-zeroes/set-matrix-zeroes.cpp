class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        // int n = matrix.size();
        // int m = matrix[0].size();

        // vector<int> row(n, 0);
        // vector<int> col(m, 0);

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < m; j++)
        //     {
        //         if(matrix[i][j] == 0)
        //         {
        //             row[i] = 1;
        //             col[j] = 1;
        //         }   
        //     }
        // }

        // for(int j = 0; j < m; j++)
        // {
        //     for(int i = 0; i < n; i++)
        //     {
        //         if(row[i] == 1 || col[j])
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }

        // return;

// -----------------------------------
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0;
        int c = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0) r = 1;
                    else matrix[i][0] = 0;

                    if(j == 0) c = 1;
                    else matrix[0][j] = 0;
                }   
            }
        }

        for(int j = 1; j < m; j++)
        {
            for(int i = 1; i < n; i++)
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if(r)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if(c)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }

        return;
    }
};
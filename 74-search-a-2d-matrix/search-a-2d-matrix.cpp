class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // for(int i = n-1; i >= 0; i--)
        // {   
        //     if(matrix[i][m-1] < target) continue;

        //     if(matrix[i][m-1] == target) return true;

        //     for(int j = m-1; j >= 0; j--)
        //     {
        //         if(matrix[i][j] == target) return true;
        //     }
        // }

        // return false;

// --------------------------------------------------------------------------------
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = n*m;

        while(l < r)
        {
            int mid = (r-l)/2 + l;

            int midx = mid/m;
            int midy = mid%m;

            if(matrix[midx][midy] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if(l < n*m && matrix[l/m][l%m] == target) return true;

        return false;
    }
};
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

        // not efficient approach

// --------------------------------------------------------------------------------
        int n = matrix.size();
        int m = matrix[0].size();

        // binary search on row to find a row element less than or equal to the target

        int l = 0;

        int r = n-1;

        while(l < r)
        {
            int mid = (r-l+1)/2 + l;

            if(matrix[mid][0] <= target)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        // now l stores the index of the row that must contain the answer

        int correct_row = l;

        l = 0;

        r = m-1;

        while(l <= r)
        {
            int mid = (r-l)/2 + l;

            if(matrix[correct_row][mid] == target)
            {
                return true;
            }
            else if(matrix[correct_row][mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return false;


    }
};
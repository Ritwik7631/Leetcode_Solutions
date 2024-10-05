class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = n-1; i >= 0; i--)
        {   
            if(matrix[i][m-1] < target) continue;

            if(matrix[i][m-1] == target) return true;

            for(int j = m-1; j >= 0; j--)
            {
                if(matrix[i][j] == target) return true;
            }
        }

        return false;
    }
};
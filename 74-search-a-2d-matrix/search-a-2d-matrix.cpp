class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();

        int m = matrix[0].size();

        int l = 0;
        int r = n*m - 1;

        while(l < r)
        {
            int mid = l + (r-l)/2;

            pair<int,int> mid_coordinates;

            mid_coordinates.first = mid / m;
            mid_coordinates.second = mid % m;

            if(matrix[mid_coordinates.first][mid_coordinates.second] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return matrix[l/m][l%m] == target;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                // Store the four elements involved in the rotation
                int temp = matrix[i][j];
                
                // Move values from left to top
                matrix[i][j] = matrix[n - 1 - j][i];
                
                // Move values from bottom to left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                
                // Move values from right to bottom
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                
                // Assign temp (top) to right
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

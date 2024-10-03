class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < (n+1)/2; i++) {
            for(int j = i; j < n - 1 - i; j++) {
                // Define the four points that need to be swapped
                int x1 = i, y1 = j;
                int x2 = j, y2 = n - 1 - i;
                int x3 = n - 1 - i, y3 = n - 1 - j;
                int x4 = n - 1 - j, y4 = i;

                // Perform the four-way swap
                int temp = matrix[x1][y1];
                matrix[x1][y1] = matrix[x4][y4];
                matrix[x4][y4] = matrix[x3][y3];
                matrix[x3][y3] = matrix[x2][y2];
                matrix[x2][y2] = temp;
            }
        }
    }
};

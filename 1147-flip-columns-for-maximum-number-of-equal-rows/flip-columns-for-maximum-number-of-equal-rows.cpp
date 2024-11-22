class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mx = 0;

        for (int i = 0; i < n; i++) {
            vector<int> temp = matrix[i]; 
            int count = 0;

            for (int j = 0; j < n; j++) {
                bool isSame = true, isOpposite = true;

                for (int k = 0; k < m; k++) {
                    if (temp[k] != matrix[j][k]) isSame = false;
                    if (temp[k] == matrix[j][k]) isOpposite = false;

                    if (!isSame && !isOpposite) break;
                }

                if (isSame || isOpposite) count++;
            }

            mx = max(mx, count);
        }

        return mx;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rdel = {0, -1, 0, 1};
        vector<int> cdel = {1, 0, -1, 0};

        // right, down, left, up

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> mark(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        int new_x = i + rdel[k];
                        int new_y = j + cdel[k];
                        while(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && matrix[new_x][new_y] != 0){
                            mark[new_x][new_y] = 1;
                            new_x += rdel[k];
                            new_y += cdel[k];
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mark[i][j]) matrix[i][j] = 0;
            }
        }

        return;
    }
};
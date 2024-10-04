class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < (n+1)/2; i++)
        {
            pair<int,int> p1 = {i,i};
            pair<int,int> p2 = {i, n-1-i};
            pair<int,int> p3 = {n-1-i, n-1-i};
            pair<int,int> p4 = {n-1-i,i};

            for(int j = p1.second; j < p2.second; j++)
            {
                swap(matrix[p1.first][p1.second], matrix[p2.first][p2.second]);
                swap(matrix[p1.first][p1.second], matrix[p3.first][p3.second]);
                swap(matrix[p1.first][p1.second], matrix[p4.first][p4.second]);

                p1.second = p1.second + 1;
                p2.first = p2.first + 1;
                p3.second = p3.second - 1;
                p4.first = p4.first - 1;
            }
        }

        return;
        
    }
};
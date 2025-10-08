class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> current = {0,0};
        int dir = 0;
        // 0 = right, 1 = down, 2 = left, 3 = up
        vector<int> rdel = {0, 1, 0, -1};
        vector<int> cdel = {1, 0, -1, 0};
        set<vector<int>> visited;

        vector<int> ans;

        while(ans.size() < n*m){
            visited.insert(current);
            ans.push_back(matrix[current[0]][current[1]]);
            
            int new_x = current[0] + rdel[dir];
            int new_y = current[1] + cdel[dir];

            if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || visited.count({new_x, new_y})){
                dir = (dir + 1) % 4;
                new_x = current[0] + rdel[dir];
                new_y = current[1] + cdel[dir];
            }

            current[0] = new_x;
            current[1] = new_y;
        }

        return ans;
    }
};
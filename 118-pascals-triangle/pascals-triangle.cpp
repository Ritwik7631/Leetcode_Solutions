class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        vector<vector<long long>> grid(n, vector<long long> (n, 1));

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }

        for(int i = 0; i < n; i++)
        {
            int j = 0;

            vector<int> temp;

            int x = i;

            while(x >= 0 && j <= i)
            {
                temp.push_back(grid[x][j]);
                x--;
                j++;
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
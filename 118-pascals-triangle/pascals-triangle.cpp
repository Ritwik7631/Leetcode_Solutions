class Solution {
public:
    vector<vector<int>> generate(int n) {
        // vector<vector<int>> ans;

        // vector<vector<long long>> grid(n, vector<long long> (n, 1));

        // for(int i = 1; i < n; i++)
        // {
        //     for(int j = 1; j < n; j++)
        //     {
        //         grid[i][j] = grid[i-1][j] + grid[i][j-1];
        //     }
        // }

        // for(int i = 0; i < n; i++)
        // {
        //     int j = 0;

        //     vector<int> temp;

        //     int x = i;

        //     while(x >= 0 && j <= i)
        //     {
        //         temp.push_back(grid[x][j]);
        //         x--;
        //         j++;
        //     }

        //     ans.push_back(temp);
        // }

        // return ans;

// ---------------------------------------------

    vector<vector<int>> ans;

    ans.push_back({1});

    if(n == 1) return ans;

    ans.push_back({1,1});

    if(n == 2) return ans;

    for(int i = 2; i < n; i++)
    {
        // vector<int> temp;
        ans.push_back({});
        ans[i].push_back(1);
        for(int j = 1; j < ans[i-1].size(); j++)
        {
            ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
        }
        ans[i].push_back(1);
        // ans.push_back(temp);
    }

    return ans;

    }
};
class Solution {
public:
    void DFS(int i, vector<vector<int>> &grph, vector<int> &vis, int &X)
    {
        vis[i] = 1;
        X++;
        for(auto a : grph[i])
        {
            if(vis[a] == 0)
            {
                DFS(a, grph, vis, X);
            }
        }

        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        vector<vector<int>> grph(n);

        for(int i = 0; i < n; i++)
        {
            vector<int> rock = stones[i];
            int x = rock[0];
            int y = rock[1];
            for(int j = i+1; j < n; j++)
            {
                vector<int> pebble = stones[j];
                int px = pebble[0];
                int py = pebble[1];

                if(px == x || py == y)
                {
                    grph[i].push_back(j);
                    grph[j].push_back(i);
                }
            }
        }

        // for(int i = 0; i < grph.size(); i++)
        // {
        //     cout << "parent: " << i << endl;
        //     cout << "children: ";
        //     for(auto a : grph[i])
        //     {
        //         cout << a << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                int a = 0;
                DFS(i, grph, vis, a);
                ans += (a - 1);
                // cout << "i: " << i << " " << "a: " << a << endl;
            }
        }

        return ans;

    }
};
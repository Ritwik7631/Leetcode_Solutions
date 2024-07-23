#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    // Find with path compression
    int findpar(vector<int>& parent, int X) {
        if (parent[X] == X) return X;
        return parent[X] = findpar(parent, parent[X]);
    }

    // Union with size update
    void merge(vector<int>& parent, vector<int>& size, int X, int Y) {
        int rootX = findpar(parent, X);
        int rootY = findpar(parent, Y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY]; // Update the size of the root component
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n);
        vector<int> size(n * n, 1); // Initialize size array to 1 for each cell

        // Initialize each node's parent to itself
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        vector<int> rdel = {-1, 0, 1, 0};
        vector<int> cdel = {0, 1, 0, -1};

        // First pass: Union all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int a = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + rdel[k];
                        int ny = j + cdel[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int b = nx * n + ny;
                            merge(parent, size, a, b); // Merge adjacent 1s
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int k = 0; k < 4; k++)
                {
                    int nx = i + rdel[k];
                    int ny = j + cdel[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n)
                    {
                        if(grid[nx][ny] == 1)
                        {
                            components.insert(findpar(parent, nx*n + ny));
                        }
                    }
                }
                int total = 0;
                for(auto it : components)
                {
                    total += size[it];
                }
                ans = max(ans, total + 1);
            }
        }

        for(int i = 0; i < n*n; i++)
        {
            ans = max(ans, size[findpar(parent, i)]);
        }

        return ans;
    }
};
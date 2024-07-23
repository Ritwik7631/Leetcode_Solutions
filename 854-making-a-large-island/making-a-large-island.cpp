#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    // Find with path compression
    int findpar(vector<int>& parent, int X) {
        if (parent[X] == X) return X;
        return parent[X] = findpar(parent, parent[X]);
    }

    // Plain union
    void merge(vector<int>& parent, int X, int Y) {
        int rootX = findpar(parent, X);
        int rootY = findpar(parent, Y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n);

        // Initialize each node's parent to itself
        for (int i = 0; i < parent.size(); i++) {
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
                            merge(parent, a, b); // Merge adjacent 1s
                        }
                    }
                }
            }
        }

        // Calculate the size of each island using a map
        unordered_map<int, int> islandSize;
        for (int i = 0; i < n * n; ++i) {
            int root = findpar(parent, i);
            if (grid[i / n][i % n] == 1) {
                islandSize[root]++;
            }
        }

        int maxIsland = 0;
        // Find the initial largest island
        for (auto& a : islandSize) {
            maxIsland = max(maxIsland, a.second);
        }

        // Second pass: Check each 0 to find the largest possible island
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    set<int> components;
                    int newSize = 1; // Size of the new island if this 0 is changed to 1
                    for (int k = 0; k < 4; k++) {
                        int nx = i + rdel[k];
                        int ny = j + cdel[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                            int root = findpar(parent, nx * n + ny);
                            components.insert(root); // Add unique roots of adjacent islands
                        }
                    }
                    for (auto it : components) {
                        newSize += islandSize[it]; // Sum the sizes of adjacent islands
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};

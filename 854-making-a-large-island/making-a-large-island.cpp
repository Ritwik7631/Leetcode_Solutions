class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

    // Find with path compression
    int findpar(vector<int>& parent, int X) {
        if (parent[X] == X) return X;
        return parent[X] = findpar(parent, parent[X]);
    }

    // Union with size tracking
    void unionBySize(vector<int>& parent, vector<int>& size, int X, int Y) {
        int rootX = findpar(parent, X);
        int rootY = findpar(parent, Y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> parent(n * n);
        vector<int> size(n * n, 1); // Initialize size array to 1 for each cell

        // Initialize each node's parent to itself
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        vector<int> rdel = {-1, 0, 1, 0};
        vector<int> cdel = {0, -1, 0, 1};

        // Step 1: Union adjacent 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + rdel[ind];
                    int newc = col + cdel[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        unionBySize(parent, size, nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Check each 0 to find the largest possible island
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + rdel[ind];
                    int newc = col + cdel[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(findpar(parent, newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: Find the largest island without flipping any 0 to 1
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, size[findpar(parent, cellNo)]);
        }

        return mx;
    }
};
class Solution {
public:
    // Function to find the ultimate parent of a node with path compression.
    int findpar(vector<int> &parent, int X) {
        if (parent[X] == X) 
            return X; // If X is its own parent, return X (ultimate parent)
        
        return parent[X] = findpar(parent, parent[X]); // Path compression
    }

    // Function to merge two sets containing X and Y.
    void merge(vector<int> &parent, int X, int Y) {
        int upx = findpar(parent, X); // Find the ultimate parent of X
        int upy = findpar(parent, Y); // Find the ultimate parent of Y
        if (upx == upy) return; // If they have the same ultimate parent, they are already connected

        parent[upy] = upx; // Set the parent of upy to be upx (union operation)
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(); // Size of the grid (assumed to be n x n)

        // Vector to keep track of parents for each node
        vector<int> parents(n * n);

        // Map to store coordinates of each value in the grid
        unordered_map<int, pair<int, int>> mp;

        // Initialize parent of each cell to itself and record its position
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                parents[grid[i][j]] = grid[i][j]; // Each value is its own parent initially
                mp[grid[i][j]] = {i, j}; // Store the coordinates of each value
            }   
        }

        int a = grid[0][0]; // Starting point (top-left corner value)
        int b = grid[n-1][n-1]; // Ending point (bottom-right corner value)

        int t = 0; // Time starts from 0

        // Row and column directions for the four possible adjacent cells (up, right, down, left)
        vector<int> rdel = {-1, 0, 1, 0};
        vector<int> cdel = {0, 1, 0, -1};

        // Continue until we can connect the start and end
        while (findpar(parents, a) != findpar(parents, b)) {    
            t++; // Increment the time, allowing one more cell to become swimmable

            // Get the coordinates of the cell with value `t`
            int x = mp[t].first;
            int y = mp[t].second;

            // Iterate through all four adjacent cells
            for (int i = 0; i < 4; i++) {
                int nx = x + rdel[i]; // New x-coordinate
                int ny = y + cdel[i]; // New y-coordinate

                // Check if the new coordinates are within bounds of the grid
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    // If the neighboring cell value is less than or equal to the current cell value, merge them
                    if (grid[nx][ny] <= grid[x][y]) {
                        merge(parents, grid[x][y], grid[nx][ny]);
                    }
                }
            }
        }

        return t; // Return the time needed to connect start and end
    }
};

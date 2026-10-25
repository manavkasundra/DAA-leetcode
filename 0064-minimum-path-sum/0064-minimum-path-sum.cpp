class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 1. Fill the first row (you can only reach these cells from the left)
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }
        
        // 2. Fill the first column (you can only reach these cells from above)
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }
        
        // 3. Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // To reach grid[i][j], you either come from above or from the left.
                // We add the smaller of those two paths to the current cell's value.
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        // 4. The bottom-right cell now holds the minimum path sum
        return grid[m-1][n-1];
    }
};
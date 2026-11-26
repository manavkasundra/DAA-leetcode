class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Make sure the first number in every row is 1
        // (In binary, the leftmost bit is always worth the most!)
        for (int r = 0; r < rows; r++) {
            if (grid[r][0] == 0) {
                // Flip the entire row (0 becomes 1, 1 becomes 0)
                for (int c = 0; c < cols; c++) {
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }

        // Step 2: Check every other column; if it has more 0s than 1s, flip it
        for (int c = 1; c < cols; c++) {
            int ones = 0;
            int zeros = 0;

            for (int r = 0; r < rows; r++) {
                if (grid[r][c] == 1) ones++;
                else zeros++;
            }

            if (zeros > ones) {
                // Flip the entire column
                for (int r = 0; r < rows; r++) {
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }

        // Step 3: Turn each binary row into a normal number and add them up
        int totalScore = 0;
        for (int r = 0; r < rows; r++) {
            int rowValue = 0;
            for (int c = 0; c < cols; c++) {
                rowValue = rowValue * 2 + grid[r][c];
            }
            totalScore += rowValue;
        }

        return totalScore;
    }
};
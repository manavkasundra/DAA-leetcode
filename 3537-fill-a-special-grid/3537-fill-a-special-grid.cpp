class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        if (n == 0) {
            return {{0}};
        }

        vector<vector<int>> small = specialGrid(n - 1);

        int half = small.size();
        int size = half * 2;
        int block = half * half;

        vector<vector<int>> grid(size, vector<int>(size));

        for (int i = 0; i < half; i++) {
            for (int j = 0; j < half; j++) {
                int value = small[i][j];

                grid[i][j + half] = value;
                grid[i + half][j + half] = value + block;
                grid[i + half][j] = value + 2 * block;
                grid[i][j] = value + 3 * block;
            }
        }

        return grid;
    }
};
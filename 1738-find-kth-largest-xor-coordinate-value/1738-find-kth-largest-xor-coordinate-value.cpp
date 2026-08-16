class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) matrix[i][j] ^= matrix[i-1][j];
                if (j > 0) matrix[i][j] ^= matrix[i][j-1];
                if (i > 0 && j > 0) matrix[i][j] ^= matrix[i-1][j-1];
                ans.push_back(matrix[i][j]);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans[ans.size() - k];
    }
};
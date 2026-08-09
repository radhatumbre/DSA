class NumMatrix {
public:
    vector<vector<int>> prefix;
    int n;
    int m;
    NumMatrix(vector<vector<int>>& mat) {
        this->n = mat.size();
        this->m = mat[0].size();
        prefix = mat;

        // Step 1: Compute row-wise prefix sums
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }

        // Step 2: Compute column-wise prefix sums
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                prefix[i][j] += prefix[i - 1][j];
            }
        }
    }
    int val(int row, int col) {

        if (row < 0 || col < 0)
            return 0;

        return prefix[row][col];
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int whole = val(row2, col2);
        int top = val(row1 - 1, col2);
        int left = val(row2, col1 - 1);
        int overlap = val(row1 - 1, col1 - 1);
        int ans = whole - top - left + overlap;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
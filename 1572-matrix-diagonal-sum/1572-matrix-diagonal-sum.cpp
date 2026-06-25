class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        bool isMid = false;
        for (int i = 0; i < n; i++) {
            sum += mat[i][i] + (i != n - 1 - i ? mat[i][n - 1 - i] : 0);
        }

        return sum;
    }
};
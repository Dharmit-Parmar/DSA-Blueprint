class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first where the code can fail
        int m = matrix.size();
        if (m == 0)
            return false;

        int n = matrix[0].size(); // for the m x n

        // now we compare the target with the end of each col if lesser then we
        // search in that
        int found_col = -1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] >= target) {
                found_col = i;
                break ;
            }
        }

        if (found_col == -1)
            return false;
        // if it is in that col

        // Binary Search in the row
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[found_col][mid] == target)
                return true;
            else if (matrix[found_col][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};

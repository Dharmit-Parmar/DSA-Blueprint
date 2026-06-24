

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();       
        int n = matrix[0].size();    
        
        int low = 0;
        int high = (m * n) - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Map 1D index back to 2D coordinates
            int row = mid / n;
            int col = mid % n;
            
            if (matrix[row][col] == target) {
                return true; // Target found
            } else if (matrix[row][col] < target) {
                low = mid + 1; // Search right half
            } else {
                high = mid - 1; // Search left half
            }
        }
        
        return false; // Target not found
    }
};
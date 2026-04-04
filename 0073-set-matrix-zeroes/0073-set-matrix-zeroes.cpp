class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();
    
    bool firstRowHasZero = false;
    bool firstColHasZero = false;
    
    // Check if first row has zero
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }
    
    // Check if first column has zero
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }
    
    // Use first row and column to mark zeros
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Set zeros based on marks
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set zeros for first row if needed
    if (firstRowHasZero) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }
    
    // Set zeros for first column if needed
    if (firstColHasZero) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
        
    }
};
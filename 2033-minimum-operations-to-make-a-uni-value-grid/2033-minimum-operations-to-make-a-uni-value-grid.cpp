class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        
        int n = grid.size();
        int m = grid[0].size();
        
        temp.reserve(n * m);  // avoid reallocations
        
        int base = grid[0][0];

        // Flatten + feasibility check
        for (auto &row : grid) {
            for (int val : row) {
                if (abs(val - base) % x != 0) {
                    return -1;
                }
                temp.push_back(val);
            }
        }

        // Sort
        sort(temp.begin(), temp.end());

        // Median
        int target = temp[temp.size() / 2];

        // Count operations
        int ops = 0;
        for (int val : temp) {
            ops += abs(val - target) / x;
        }

        return ops;
    }
};
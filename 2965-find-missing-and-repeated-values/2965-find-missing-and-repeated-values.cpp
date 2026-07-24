class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;

        long long actual = 1LL * m * (m + 1) / 2;
        long long actualSquare = 1LL * m * (m + 1) * (2 * m + 1) / 6;

        long long thisSum = 0;
        long long thisSqSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                thisSum += grid[i][j];
                thisSqSum += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long xminusy = thisSum - actual;          // x - y
        long long sqDif = thisSqSum - actualSquare;    // x² - y²
        long long xplusy = sqDif / xminusy;            // x + y

        long long rep = (xminusy + xplusy) / 2;
        long long mis = xplusy - rep;

        return {(int)rep, (int)mis};
    }
};
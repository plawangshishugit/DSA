class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        // Building 1 always has height 0
        restrictions.push_back({1, 0});

        // Building n can be at most n-1
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Forward pass
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        // Backward pass
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        int ans = 0;

        // Find the maximum possible peak between every pair
        for (int i = 1; i < m; i++) {

            int x1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];

            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int d = x2 - x1;

            // Maximum peak between the two restrictions
            int peak = (h1 + h2 + d) / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};
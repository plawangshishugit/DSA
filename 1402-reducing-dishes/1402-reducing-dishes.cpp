class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        int suffixSum = 0;
        int ans = 0;

        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            if (suffixSum + satisfaction[i] > 0) {
                suffixSum += satisfaction[i];
                ans += suffixSum;
            } else {
                break;
            }
        }

        return ans;
    }
};
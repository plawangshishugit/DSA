class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {

        int n = nums.size();

        vector<int> maxPre(n);
        vector<int> minSuff(n);

        // build prefix maximum
        maxPre[0] = nums[0];

        for(int i = 1; i < n; i++) {
            maxPre[i] = max(maxPre[i - 1], nums[i]);
        }

        // build suffix minimum
        minSuff[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            minSuff[i] = min(minSuff[i + 1], nums[i]);
        }

        vector<int> ans(n);

        ans[n - 1] = maxPre[n - 1];

        for(int i = n - 2; i >= 0; i--) {

            if(maxPre[i] > minSuff[i + 1]) {
                ans[i] = ans[i + 1];
            }
            else {
                ans[i] = maxPre[i];
            }
        }

        return ans;
    }
};
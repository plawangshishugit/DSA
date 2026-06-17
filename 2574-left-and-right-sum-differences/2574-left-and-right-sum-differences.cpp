class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for (int x : nums)
            total += x;

        vector<int> ans(n);
        int prefix = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int left = prefix - nums[i];
            int right = total - prefix;
            ans[i] = abs(left - right);
        }

        return ans;
    }
};
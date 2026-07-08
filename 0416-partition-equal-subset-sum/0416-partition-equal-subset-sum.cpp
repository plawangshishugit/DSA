class Solution {
public:
    vector<vector<int>> dp;

    bool fun(vector<int>& nums, int i, int currSum, int target) {

        if(currSum == target)
            return true;

        if(i == nums.size() || currSum > target)
            return false;

        if(dp[i][currSum] != -1)
            return dp[i][currSum];

        bool take = fun(nums, i + 1, currSum + nums[i], target);

        bool notTake = fun(nums, i + 1, currSum, target);

        return dp[i][currSum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;

        for(int x : nums)
            total += x;

        if(total % 2)
            return false;

        int target = total / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return fun(nums, 0, 0, target);
    }
};
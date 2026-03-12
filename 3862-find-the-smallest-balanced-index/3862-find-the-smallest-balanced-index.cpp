class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        const long long LIMIT = 1e14;

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + nums[i];

        long long rightProduct = 1;
        int ans = -1;

        for(int i = n-1; i >= 0; i--) {

            long long leftSum = (i == 0) ? 0 : prefix[i-1];

            if(leftSum == rightProduct)
                ans = i;

            if(rightProduct > LIMIT / nums[i])
                rightProduct = LIMIT + 1;
            else
                rightProduct *= nums[i];
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l = nums.size();
        int sum = 0;
        if(l<2){
            return {0};
        }
        for(int i =0; i<l; i++){
            sum += nums[i];
        }
        vector<int>ans(l,0);
        int pSum = 0;
        for(int i =0; i<l; i++){
            pSum += nums[i];
            int temp = sum - pSum;
            ans[i] = abs(temp - (pSum - nums[i]));
        }
        return ans;
    }
};
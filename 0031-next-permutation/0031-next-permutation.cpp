class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        int size = nums.size();
        int breakPoint = -1;
        // find the decreasing element from right
        for(int i = size-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                breakPoint = i;
                break;
            }
        }


        // if no breakpoint, so reverse entire array
        if(breakPoint == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        swap(nums[breakPoint],nums[breakPoint+1]);
        // reverse the array
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
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

        // find element just greater than nums[breakpoint] and swap it wiht breakpoint if you traverse from back then the first element you fount greater than the breakpoint it is the element to swap
        for(int i = size-1; i> breakPoint; i--){
            if(nums[i] > nums[breakPoint]) {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }
        // reverse the array
        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
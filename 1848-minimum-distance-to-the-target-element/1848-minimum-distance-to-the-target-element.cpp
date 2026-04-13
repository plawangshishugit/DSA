class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDis = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == target){
                minDis = min(minDis, abs(i-start));
            }
        }
        return minDis;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0; 
        int n = nums.size();
        int maxCnt =0;
        for(int i =0; i<n; i++){
            if(nums[i] == 1){
                cnt += 1;
                maxCnt = max(cnt,maxCnt);
            }
            else{
                cnt =0;
            }
        }
        return maxCnt;
    }
};
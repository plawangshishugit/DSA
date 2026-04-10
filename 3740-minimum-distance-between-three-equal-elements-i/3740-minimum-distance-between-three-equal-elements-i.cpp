class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minDis = INT_MAX;
        bool isFound = false;
        int n = nums.size();
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                for(int k= j+1; k<n; k++){
                    if(nums[i] == nums[j] && nums[i] == nums[k]){
                        int dis = abs(i-j) + abs(j-k) + abs(i-k);
                        isFound = true;
                        if(dis < minDis){
                            minDis = dis;
                        }
                    }
                }
            }
        }
        if(isFound){
            return minDis;
        }
        else{
            return -1;
        }
    }
};
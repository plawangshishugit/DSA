class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++){
            int low = i + 1;
            int high = n - 1;

            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];

                if(abs(target - sum) < abs(target - closestSum)){
                    closestSum = sum;
                }

                if(sum < target){
                    low++;
                } else if(sum > target){
                    high--;
                } else {
                    return sum; 
                }
            }
        }
        return closestSum;
    }
};
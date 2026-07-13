class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int>mp;
        mp[nums[0]] = 0;
        for(int i=1; i<n; i++){
            int rem = target - nums[i]; 
            if(mp.find(rem) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                return {mp[rem],i};
            }
        }
        return {} ;
    }
};
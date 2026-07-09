class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int cnt = 0; 
        int psum =0;
        int rem = 0;
        for(int i =0; i<n; i++){
            psum = psum + nums[i];
            rem = psum -k;
            if(mp.find(rem) != mp.end()){
                cnt = cnt + mp[rem];
            }
            mp[psum]++;
        }
        return cnt;
    }
};
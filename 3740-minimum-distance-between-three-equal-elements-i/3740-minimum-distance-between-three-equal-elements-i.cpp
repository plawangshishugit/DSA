class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int minDis = INT_MAX;
        bool found = false;
        for(auto &it: mp){
            vector<int>&idx = it.second;
            if(idx.size() >= 3){
                for(int i =0; i+2 <idx.size(); i++){
                    int dis = 2 * (idx[i+2] - idx[i]);
                    minDis = min(minDis, dis);
                    found = true;
                }
            }
        }
        return found ? minDis : -1;
    }
};
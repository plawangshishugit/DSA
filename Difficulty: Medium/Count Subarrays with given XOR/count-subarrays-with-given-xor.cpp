class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int xr = 0;
        unordered_map<int,int>mp;
        mp[0]++;
        int cnt = 0;
        for(int i =0; i<arr.size(); i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
            cnt += mp[x];
            mp[xr]++;
        }
        return cnt;
    }
};
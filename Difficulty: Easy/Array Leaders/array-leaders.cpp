class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int sufMax = 0;
        int n = arr.size();
        vector<int>ans;
        for(int i =n-1; i>=0; i--){
            if(arr[i]>=sufMax){
                ans.push_back(arr[i]);
                sufMax = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
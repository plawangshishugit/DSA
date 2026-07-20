class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        ans.push_back(arr[0]);
        int cnt =  0;
        for(int i =1; i<n; i++){
            if(arr[i][0] <= ans[cnt][1]){
                ans[cnt][1] = max(ans[cnt][1], arr[i][1]);
            }
            else{
                ans.push_back(arr[i]);
                cnt += 1;
            }
        }
        return ans;
    }
};
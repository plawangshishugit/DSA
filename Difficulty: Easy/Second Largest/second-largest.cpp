class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n < 2){
            return -1;
        }
        int secondMax = INT_MIN;
        int firstMax = INT_MIN + 1;
        for(int i =0; i<n; i++){
            firstMax = max(firstMax, arr[i]);
        }
        for(int i =0; i<n; i++){
            if(arr[i]<firstMax && arr[i]> secondMax){
                secondMax = arr[i];
            }
        }
        if(secondMax != INT_MIN){
            return secondMax;
        }
        else{
            return -1;
        }
    }
};
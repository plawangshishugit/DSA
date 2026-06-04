class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int l  = arr.size();
        int maximum = INT_MIN;
        for(int i =0; i<l; i++){
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }
};

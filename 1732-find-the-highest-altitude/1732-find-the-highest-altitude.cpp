class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int st = 0;
        int maxi = 0;
        for(int i =0; i<n;i++){
            maxi = max(maxi, st+gain[i]);
            st = st + gain[i];
        }
        return maxi;
    }
};
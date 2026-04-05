class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lmost(n), rmost(n);
        int res = 0;

        // left max array
        lmost[0] = height[0];
        for(int i = 1; i < n; i++){
            lmost[i] = max(lmost[i-1], height[i]);
        }

        // right max array
        rmost[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rmost[i] = max(rmost[i+1], height[i]);
        }

        // calculate water
        for(int i = 0; i < n; i++){
            res += min(lmost[i], rmost[i]) - height[i];
        }

        return res;
    }
};
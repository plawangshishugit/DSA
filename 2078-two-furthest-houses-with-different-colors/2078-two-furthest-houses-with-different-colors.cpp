class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                if(colors[i] != colors[j]){
                    int len = abs(i-j);
                    if(len > ans){
                        ans = len;
                    }
                }
                
            }
        }
        return ans;
    }
};
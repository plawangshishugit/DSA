class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low =0, high = n-1, maxArea = 0;
        while(low < high){
            int width = high - low;
            int currentArea = width * min(height[low], height[high]);
            maxArea = max(maxArea, currentArea);
            if(height[low] < height[high]){
                low += 1;
            }
            else{
                high -= 1;
            }
        }
        return maxArea;
    }
};
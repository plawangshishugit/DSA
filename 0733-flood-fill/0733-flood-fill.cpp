class Solution {
private:
    void dfs(vector<vector<int>>&image,int iniColor, int newColor, int i, int j){
        int n = image.size();
        int m = image[0].size();
        if(i>=n || j>= m) return;
        if(i<0 || j<0) return;
        if(image[i][j] != iniColor){
            return;
        }

        image[i][j] = newColor;

        dfs(image,iniColor, newColor,i+1,j);
        dfs(image, iniColor, newColor,i-1,j);
        dfs(image, iniColor,newColor,i,j+1);
        dfs(image, iniColor,  newColor,i,j-1);
        
        
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        int newColor = color;
        if(iniColor != newColor)dfs(image,iniColor,  newColor, sr, sc);
        return image;
    }

};
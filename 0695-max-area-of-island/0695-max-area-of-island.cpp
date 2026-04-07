class Solution {
private:
    int dfs(vector<vector<int>>&grid, int i , int j){
        if(i <0 || i == grid.size() || j<0 || j== grid[0].size() || grid[i][j] ==0){
            return 0;
        }
        int count = 1;
        grid[i][j] = 0;
        count += dfs(grid, i+1, j);
        count += dfs(grid, i-1, j);
        count += dfs(grid, i, j+1);
        count += dfs(grid, i, j-1);
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    if(area > max_area){
                        max_area = area;
                    }
                }
            }
        }
        return max_area;
    }
};
class Solution {
private:
    void dfs(vector<vector<char>>&grid, int i, int j, vector<vector<bool>>&vis){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>= n || j>= m)return;
        if(vis[i][j] || grid[i][j] == '0')return;
        vis[i][j] = true;
        dfs(grid,i-1,j,vis);
        dfs(grid,i+1,j,vis);
        dfs(grid,i,j-1,vis);
        dfs(grid,i,j+1,vis);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0; 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] != true){
                    dfs(grid,i,j,vis);
                    cnt+= 1;
                }
            }
        }
        return cnt;
    }
};
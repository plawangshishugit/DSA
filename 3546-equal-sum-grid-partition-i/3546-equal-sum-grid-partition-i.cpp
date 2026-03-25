class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        long long total = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                total += grid[i][j];
            }
        }
        //we have sum of all boxes
        // approach is like presum
        // first is row wise
        long long rowSum = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++){
                rowSum += grid[i][j];
            }
            long long rem = total - rowSum;
            if(rem == rowSum ){
                return true;
            }
        }

        //col wise
        long long colSum = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                colSum += grid[j][i];
            }
            long long rem = total - colSum;
            if(rem == colSum ){
                return true;
            }
        }
        return false;
    }
};
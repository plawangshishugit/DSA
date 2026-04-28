class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        bool isPossible  = true;
        int n = grid.size();
        int m = grid[0].size();
        int rem = grid[0][0] % x;
        vector<int>temp;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                temp.push_back(grid[i][j]);
                if(grid[i][j] % x != rem ){
                isPossible = false;
            }
            }
        }
        if(isPossible){
            sort(temp.begin(),temp.end());
            int len = temp.size();
            int mid = temp[(len-1)/2];
            int cnt = 0; 
            int sum = 0;
            for(int i =0; i<len; i++){
                cnt = abs(temp[i] - mid)/x;
                sum += cnt;
            }
            return sum;
        }else{
            return -1;
        }
    }
};
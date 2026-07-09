class Solution {
public:
    vector<int> addNums(int n) {
        vector<int> row;
        long long val = 1;  
        for (int r = 0; r <= n; r++) {
            row.push_back((int)val);
            val = val * (n - r) / (r + 1);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            ans.push_back(addNums(i));
        }
        return ans;
    }
};
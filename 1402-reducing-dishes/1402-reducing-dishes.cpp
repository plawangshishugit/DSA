class Solution {
public:
    int solve(vector<int>&satisfaction, int i , int t, int n , vector<vector<int>>&dp){
        if(i >= n){
            return 0;
        }
        if(dp[i][t] != -1){
            return dp[i][t];
        }
        int include = satisfaction[i] * t + solve(satisfaction, i+1, t+1, n,dp);
        int exclude = solve(satisfaction, i+1, t,n,dp);
        return dp[i][t] = max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0,1,n , dp);

    }
};
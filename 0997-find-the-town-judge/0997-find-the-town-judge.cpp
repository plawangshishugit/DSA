class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int len = trust.size();
        
        vector<vector<int>> vis(n+1); // who trusts i
        vector<int> out(n+1, 0);      // who i trusts

        for(int i = 0; i < len; i++){
            int a = trust[i][0];
            int b = trust[i][1];
            vis[b].push_back(a);
            out[a]++; // a trusts someone
        }

        for(int i = 1; i <= n; i++){
            if(vis[i].size() == n-1 && out[i] == 0){
                return i;
            }
        }

        return -1;
    }
};
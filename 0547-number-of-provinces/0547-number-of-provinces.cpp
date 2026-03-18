class Solution {
private:
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis){
        vis[node] = 1;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(adj, neighbour, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // Step 1: Create adjacency list
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Step 2: DFS to count components
        vector<int> vis(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adj, i, vis);
            }
        }

        return cnt;
    }
};
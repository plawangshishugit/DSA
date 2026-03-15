class Solution {
  public:
    void DFS(vector<vector<int>>&adj, int u, vector<bool>&visited, vector<int>&ans){
        if(visited[u] == true){
            return;
        }
        visited[u] = true;
        ans.push_back(u);
        for(int neighbour: adj[u]){
            if(!visited[neighbour]){
                DFS(adj, neighbour, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int>ans;
        vector<bool>visited(n, false);
        DFS(adj, 0, visited, ans);
        return ans;
    }
};
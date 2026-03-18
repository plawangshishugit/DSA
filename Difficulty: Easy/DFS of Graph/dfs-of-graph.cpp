class Solution {
  public:
    void DFS(vector<vector<int>>&adj, int node, vector<bool>&visited, vector<int>&ans){
        visited[node] = true;
        ans.push_back(node);
        for( auto neighbour: adj[node]){
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
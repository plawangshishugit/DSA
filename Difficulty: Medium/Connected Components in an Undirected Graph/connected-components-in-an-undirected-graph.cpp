class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& comp) {
        vis[node] = 1;
        comp.push_back(node);

        for (auto neighbour : adj[node]) {
            if (!vis[neighbour]) {
                dfs(neighbour, adj, vis, comp);
            }
        }
    }

public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: DFS to find components
        vector<int> vis(V, 0);
        vector<vector<int>> ans;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);
                ans.push_back(comp);
            }
        }

        return ans;
    }
};
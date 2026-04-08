class Solution {
public:
    bool dfs(int vertex, int par, vector<vector<int>>& adj, vector<bool>& vis){
        vis[vertex] = true;

        for(auto child : adj[vertex]){
            if(child == par) continue;

            if(vis[child]) return true;

            if(dfs(child, vertex, adj, vis)) return true;
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(V, false);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)){
                    return true;
                }
            }
        }

        return false;
    }
};
class Solution {
  public:

    bool isCycleDFS(vector<vector<int>>& adj, int node, vector<bool>& visited, int parent){
        
        visited[node] = true;

        for(int neighbour : adj[node]){

            if(!visited[neighbour]){
                if(isCycleDFS(adj, neighbour, visited, node)){
                    return true;
                }
            }
            else if(neighbour != parent){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);

        // convert edge list to adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(isCycleDFS(adj,i,visited,-1)){
                    return true;
                }
            }
        }

        return false;
    }
};
class Solution {
  public:
    bool isCycleDetected(vector<vector<int>> &adj,vector<bool> &vis,int src,int parent){
        vis[src]=true;
        for(int v=0; v<adj[src].size(); v++){
            if(!vis[adj[src][v]]){
                if(isCycleDetected(adj,vis,adj[src][v],src)){
                    return true;
                }
            }else{
                if(adj[src][v]!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        for(int i=0; i<adj.size(); i++){
            if(!vis[i]){
                if(isCycleDetected(adj,vis,i,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};
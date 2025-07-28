class Solution {
  public:
    bool isCycleDetected(vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &hasPath,int src){
        vis[src]=true;
        hasPath[src]=true;
        for(int v=0; v<adj[src].size(); v++){
            if(!vis[adj[src][v]]){
                if(isCycleDetected(adj,vis,hasPath,adj[src][v])){
                    return true;
                }
            }else{
                if(hasPath[adj[src][v]]){
                    return true;
                }
            }
        }
        hasPath[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(V,false);
        vector<bool> hasPath(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(isCycleDetected(adj,vis,hasPath,i)){
                    return true;
                }
            }
        }
        return false;
    }
};
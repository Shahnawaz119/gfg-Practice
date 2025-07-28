
class Solution {
  public:
    void DFS(vector<vector<int>> &adj,int src,vector<bool> &vis,vector<int> &temp){
        vis[src]=true;
        temp.push_back(src);
        for(int v=0; v<adj[src].size(); v++){
            if(!vis[adj[src][v]]){
                DFS(adj,adj[src][v],vis,temp);
            }
        }
        
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        vector<vector<int>> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vector<int> temp;
                DFS(adj,i,vis,temp);
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};

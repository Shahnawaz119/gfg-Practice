class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void helper(vector<int> adj[],vector<bool> &vis,int src,int desti,int &count){
        if(src==desti){
            count++;
            return;
        }        
        vis[src]=true;
        for(int v=0; v<adj[src].size(); v++){
            if(!vis[adj[src][v]]){
                helper(adj,vis,adj[src][v],desti,count);
            }
        }
        vis[src]=false;
    }
            
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int count=0;
        vector<bool> vis(V,false);
        helper(adj,vis,source,destination,count);
        return count;
        
    }
};
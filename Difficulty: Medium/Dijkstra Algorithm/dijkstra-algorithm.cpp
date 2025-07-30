// User Function Template
class Solution {
  public:
    class Edges{
      public:
      int V;
      int wt;
      Edges(int V,int wt){
          this->V=V;
          this->wt=wt;
      }
    };
    vector<int> dijkstra(vector<vector<Edges>> &graph,int src){
        vector<int> dist(graph.size(),INT_MAX);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,src));
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            
            for(int v=0; v<graph[u].size();v++){
                int weight=graph[u][v].wt;
                if(dist[u]+weight<dist[graph[u][v].V]){
                    dist[graph[u][v].V]=dist[u]+weight;
                    pq.push(make_pair(dist[graph[u][v].V],graph[u][v].V));
                }
            }
        }
        return dist;
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<Edges>> graph(V);
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back(Edges(edges[i][1],edges[i][2]));
            graph[edges[i][1]].push_back(Edges(edges[i][0],edges[i][2]));
        }
        vector<int> dist=dijkstra(graph,src);
        return dist;
    }
};
void topSortDFS(int src, map<int, bool>& vis, stack<int> &st){
          vis[src] =  true;

          for(auto &nbr: adjList[src]){
            if(!vis[nbr]){
              topSortDFS(nbr, vis, st);
            }
          }
          st.push(src);
}
int main(){
  Graph g;
  g.addEdge(0,5, 0);
  g.addEdge(5, 4, 0);
  g.addEdge(4, 3, 0);
  g.addEdge(0, 6, 0);
  g.addEdge(6, 3, 0);
  g.addEdge(0, 1, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(2, 3 ,0);
  int nodes = 8;
  map<int, bool> visited;
  stack<int> st;
  for(int i=0; i < nodes; i++){
    if(!visited[i]){
      g.topSortDFS(i, visited, st);
    }
  }
  return 0;
}

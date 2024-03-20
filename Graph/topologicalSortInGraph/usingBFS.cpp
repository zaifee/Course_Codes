void shortestPathBFS(int src, int destination){
  queue<int> q;
  map<int, bool> vis;
  map<int, int> parent;

  //initial state 
  q.push(src);
  vis[src] = true;
  parent[src] = -1;

  while(!q.empty()){
    int frontNode = q.front();
    q.pop();

    for(auto nbr: adjList[frontNode]){
      if(!vis[nbr]){
        q.push(nbr);
        parent[nbr] = frontNode;
        vis[nbr] = true;
      }
    }
  }

  //parent aake yaha ready hoga 
  vector<int> ans;
  while(destination != -1){
    ans.push_back(destination);
    destination = parent[destination];
  }
  reverse(begin(ans), end(ans));

  for(auto i: ans)
    cout << i << " ";
}

};

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


  


  
  int n = 7;
  int src = 0;
  int dest = 3;

   cout << "Printing the topo Order : " << endl;
  while(!st.empty()){
    cout << st.top() << " ";
    st.pop();
  }
  vector<int> topoSort;
  g.topoSortUsingBFS(nodes, topoSort);
  for(auto &i: topoSort){
    cout << i << endl;
  }
  return 0;
}

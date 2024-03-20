void topoSortUsingBFS(int n, vector<int> &topoSort){

  queue<int> q;
  map<int, int> Indegree; //storing indegree of nodes
//Initialized the degree of child 
 for(int i=0; i<n; i++){
  Indegree[i] = 0;
 }

  for(auto i: adjList){
    for(auto nbr : i.second){
      Indegree[nbr]++;
    }
  }
  
  //Push all the indegree wali node in the queue
  // for(int node=0; node < n; node++){
  //   if(Indegree[node] != 0){
  //     q.push(node);
  //   }
  // }
  for(auto node: Indegree){
    if(node.second == 0)
      q.push(node.first);
  }


//BFS chala do abb
while(!q.empty()){
  int frontNode = q.front();
  q.pop();

  topoSort.push_back(frontNode);

  for(auto nbr: adjList[frontNode]){
      Indegree[nbr]--;

      //check for zero 
      if(Indegree[nbr] == 0){
        q.push(nbr);
      }
  }
 
}
}
int main(){
  vector<int> topoSort;
  g.topoSortUsingBFS(nodes, topoSort);
  for(auto &i: topoSort){
    cout << i << endl;
  }

  if(topoSort.size() == nodes){
    cout << "No cycle present in the graph" << endl;
  }else{
    cout << "cycle present " << endl;
  }
  return 0;
}

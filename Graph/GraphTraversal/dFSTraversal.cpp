void dfsTraversal(T src, unordered_map<T, bool>& vis){
  vis[src] = true;
  cout << src << " ";

  for(auto nbr : adjList[src]){
    T nbrData = nbr.first; //bcz we have weighted graph so taking our first means node data
    if(!vis[nbrData]){
      dfsTraversal(nbrData, vis);
    }

  }
}

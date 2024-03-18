void bfsTraversal(T src, unordered_map<T, bool> &vis){
  //adjList already data member me hai 
  //visited array 
  
  //queue
  queue<T>q;
  
  //maintain the inital state 
  q.push(src);
  vis[src] = true;

  while(!q.empty()){
    T frontNode = q.front();
    cout << frontNode << " ";
    q.pop();


    //go to nbr 
    for(auto nbr: adjList[frontNode]){
      T nbrData = nbr.first;

      //check visited or not 
      if(!vis[nbrData]){
        q.push(nbrData);
        vis[nbrData] = true;
      }

    }


  }

}

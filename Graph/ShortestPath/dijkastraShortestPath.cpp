//This algorithm doesn't work for negative cycle and unreachable node. 
void dijkastraShortestPath(int n, int src, int dest){
  vector<int> dist(n+1, INT_MAX);

  set<pair<int,int> > st;

  //maintain the initial state {0, src}
  st.push({0, src});
  dist[src]= 0; //As the src node is independent node so, their distance will be 0.

   //dist update logic 
   while(!st.empty()){
    auto topElement = st.begin(); //starting ke element ka reference mil gya 
    pair<int, int> topPair = *topElement;
    int topDist = topPair.first;
    int topNode = topPair.second;
    //remove the topNode 
    st.erase(st.begin());


    //update the dist of the neighbour 
    for(pair<int, int> nbrPair: adjList[topNode]){
      int nbrNode = nbrPair.first;
      int nbrDist = nbrPair.second;

      if(topDist + nbrDist < dist[nbrNode]){
        //found a new shorter dist
        //Now update : 
        // set ki entry  
        // find out previous entry and delete it.
        auto previousEntry = st.find({dist[nbrNode], nbrNode});
        if(previousEntry != st.end()){
          // entry present in set 
          st.erase(previousEntry); 
        }
        // dist ka array
        dist[nbrNode] = topDist + nbrDist;
        // create a new entry in the set for new distance 
        st.insert({dist[nbrNode], nbrNode});
      } 
    }

   }
   cout << "Shortest dist from source " << src << " Node to " << dest << " Node: " << dist[dest] << endl;


}
int main(){
  
 g.addEdge(1, 6, 14, 0);
 g.addEdge(1, 3, 9, 0);
 g.addEdge(1, 2, 7, 0);
 g.addEdge(2, 3, 10, 0);
 g.addEdge(2, 4, 15, 0);
 g.addEdge(3, 4, 11, 0);
 g.addEdge(6, 3, 2, 0);
 g.addEdge(6, 5, 9, 0);
g.addEdge(5, 4, 6, 0);
int ni = 6;
int srci = 6;
int dest = 4;
g.dijkastraShortestPath(ni, srci, dest);
  return 0;
}


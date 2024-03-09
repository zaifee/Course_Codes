#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

template <typename> T;
// class Graph{
// public:
// unordered_map<T,list<T> > adjList;
// void addEdge(T startingEdge, T endingEdge, bool direction){
// // directed -> represented by 1 
// // undirected -> represented by 0;

//   if(direction == 1){
//     //starting edge to endingedge ek edge hai 
//     adjList[startingEdge].push_back(endingEdge);
//   }
//   else{
//     //  startingEdge -> endingEdge 
//     //  endingEdge -> startingEdge 
//     adjList[startingEdge].push_back(endingEdge);
//     adjList[endingEdge].push_back(startingEdge);
//   }
//   cout << "Printing adjList " << endl;
//   printEdgeList();
//   cout << endl;
 
// }


// void printEdgeList(){
//   for(auto i: adjList){
//     cout << i.first << "-> {";
// //printing all neighbour of each node int value
//     for(auto neighbour : i.second){
//       cout << neighbour << " , ";
//     }
//     cout << " } " << endl;

//   }
// }

// }; 


class Graph{
public:
unordered_map<int, list<pair<int,int> > > adjList;

void addEdge(int u, int v, int wt, bool direction){
  //if direction == 1 -> directed graph 
  // else direction == 0 -> undirected graph 
  if(direction == 1){
    adjList[u].push_back(make_pair(v, wt));
  }
  else{
    //undirected - u se v ek edge hai aur v se u ek edge hai 
    adjList[u].push_back({v, wt});
    adjList[v].push_back({u, wt});
  }
  printEdgeList();
  cout << endl;
}

void printEdgeList(){
  for(auto &i: adjList){
    cout << i.first << " : {";
    for(pair<int,int> p: i.second){
      cout << "{" << p.first << "," <<  p.second << "},";
    }
    cout <<"}" << endl;
  }
}

void bfsTraversal(T src){
  //adjList already data member me hai 
  //visited array 
  unordered_map<T, bool> vis;
  //queue
  queue<T>que;
  
  //maintain the inital state 
  que.push(src);
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




};






int main() {
 Graph g;
 //directed edge 
//  g.addEdge(0, 1, 1);
//  g.addEdge(1, 2, 1);
//  g.addEdge(1, 3, 1);
//  g.addEdge(1, 4, 1);

//undireted edge
// g.addEdge(0, 1, 0);
//  g.addEdge(1, 2, 0);
//  g.addEdge(1, 3, 0);
//  g.addEdge(1, 4, 0);


// edge with weigts -- directed graph
// g.addEdge(0,1, 5, 1);
// g.addEdge(1, 2, 10, 1);
// g.addEdge(2, 3, 20, 1);
// g.addEdge(3, 4, 30, 1);
// cout << endl;
// cout << endl;
// cout << "Printing the Undirected edge " << endl;
// cout << endl;
// cout << endl;

// edge with weigts -- directed graph
// g.addEdge(0,1, 5, 0);
// g.addEdge(1, 2, 10, 0);
// g.addEdge(2, 3, 20, 0);
// g.addEdge(3, 4, 30, 0);

Graph<char> g;
g.addEdge('a', 'b', 5, 0);
g.addEdge('b', 'c', 10, 0);
g.addEdge('b', 'c', 20, 0);
g.addEdge('c','d', 40, 0);




  return 0;
}

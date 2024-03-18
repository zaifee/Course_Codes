#include <iostream>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

template <typename T>
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
unordered_map<T, list<pair<T,int> > > adjList;

void addEdge(T u, T v, int wt, bool direction){
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
    for(pair<T,int> p: i.second){
      cout << "{" << p.first << "," <<  p.second << "},";


    }
    cout <<"}" << endl;
  }
}


};


int main() {
//  Graph g;
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
// g.addEdge('a', 'b', 5, 0);
// g.addEdge('d', 'c', 5, 0);
// g.addEdge('b', 'c', 10, 0);
// g.addEdge('c', 'd', 10, 0);
// g.addEdge('c', 'e', 20, 0);
// g.addEdge('e','f', 40, 0);

//for disconnected graph 
// g.addEdge('a', 'b', 10, 0);
// g.addEdge('b', 'c', 20, 0);

// g.addEdge('d', 'e', 30, 0);

// g.addEdge('f', 'f', 40, 0);

// unordered_map<char, bool> vis;
// for(char node = 'a';  node <= 'f'; node++){
//   if(!vis[node]){
//     g.bfsTraversal(node, vis); //doing traversal for every node 
//   }
// }

// g.bfsTraversal('a');


//Dfs Traversal 

g.addEdge('a', 'b', 10, 0);
// g.addEdge('a', 'c', 20, 0);
g.addEdge('c', 'd', 30, 0);
g.addEdge('c', 'e', 40, 0);
g.addEdge('d', 'e', 40, 0);
g.addEdge('e', 'f', 50, 0);
unordered_map<char, bool> vis;
for(char node = 'a';  node <= 'f'; node++){
  if(!vis[node]){
    g.dfsTraversal(node, vis);
  }
}

g.dfsTraversal('a', vis);





  return 0;
}

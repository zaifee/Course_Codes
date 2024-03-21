#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

class Graph{
public:
                  //  nbr, distance
unordered_map<int, list<pair<int, int> > > adjList;

void addEdge(int u, int v, int wt, bool direction){
  if(direction == 1){
    adjList[u].push_back({v, wt});
  }else{
    adjList[u].push_back({v, wt});
    adjList[v].push_back({u, wt});
  }
}

void printAdjList(){
  for(auto &i: adjList){
    cout << i.first << ": { ";
    for(auto &j: i.second){
      cout << "(" << j.first << "," << j.second << ")";
    }
    cout <<"}" << endl;
  }
}

void topoOrderDFS(int src, stack<int>& topoOrder, unordered_map<int, bool>& vis){

  vis[src] = true;
  for(auto &nbrPair: adjList[src]){
    int nbrNode = nbrPair.first;
    // int nbrDist = nbrPair.second;
    if(!vis[nbrNode]){
      topoOrderDFS(nbrNode, topoOrder, vis);
    }
  }
  topoOrder.push(src);

}
void shortestPathDFS(stack<int>& topoOrder, int n){
  //n here represent no of nodes 

  //taking a distance array of n length which stores the shortest path of node
  vector<int> distance(n, INT_MAX);


  //initally maintain src 
  int src = topoOrder.top();
  topoOrder.pop();
  distance[src] = 0;

  //Update nbr distance for the source node 
  for(auto nbrPair: adjList[src]){
    int nbrNode = nbrPair.first;
    int nbrDist = nbrPair.second; //dist 
// src node + jo hamari hai edge uski dist  < jis node par hmm pohuch rahe hai usse kam hai to usse update kar denge 
    if(distance[src] + nbrDist < distance[nbrNode]){
      distance[nbrNode] = distance[src] + nbrDist;
    }
  }

  //apply the same above concept for all the above nodes 
  //in the topoOrdering 
  while(!topoOrder.empty()){
    int src = topoOrder.top();
    topoOrder.pop();

    for(auto nbrPair: adjList[src]){
    int nbrNode = nbrPair.first;
    int nbrDist = nbrPair.second; //dist 
// src node + jo hamari hai edge uski dist  < jis node par hmm pohuch rahe hai usse kam hai to usse update kar denge 
    if(distance[src] + nbrDist < distance[nbrNode]){
      distance[nbrNode] = distance[src] + nbrDist;
    }
  }

  }

  //ab mera distance array bilkul ready hai 
  cout << "Printing the distance array :" << endl;
  for(auto i: distance){
    cout << i << " ";
  }  

}


};

int main() {
  
  Graph g;
  g.addEdge(0, 1, 5, 1);
  g.addEdge(0, 2, 3, 1);
  g.addEdge(2, 1, 2, 1);
  g.addEdge(1, 3, 3, 1);
  g.addEdge(2, 3, 5, 1);
  g.addEdge(2, 4, 6, 1);
  g.addEdge(4,3 , 1,1);

  int n = 5;
  g.printAdjList();

  int src = 0;
  stack<int> topoOrder;
  unordered_map<int, bool> vis;
  g.topoOrderDFS(src, topoOrder, vis);
  // cout << "Printing the topoOrder " << endl;
  // while(!topoOrder.empty()){
  //   cout << topoOrder.top() << " ";
  // topoOrder.pop();
  // }
  g.shortestPathDFS(topoOrder, n);
 
  
  
   return 0;
}

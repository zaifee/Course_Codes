#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

class Graph{
public:
unordered_map<int , list<pair<int, int> > > adjList;

void addEdge(int u, int v, int wt, bool direction){
  if(direction == 0){
    adjList[u].push_back({v, wt});
    adjList[v].push_back({u, wt});
  }else{
    adjList[u].push_back({v, wt});
  }
}

void printList(){
  
for(auto &i: adjList){
  cout << i.first <<":";
  for(auto &j: i.second){
    cout << "{" << j.first << "," << j.second << "}" ;
  }
  cout << endl;
}


}

// void bellManFord(int n, int src){
  //dist array 
  // vector<int> dist(n, INT_MAX);
  // //initial state 
  // dist[src] = 0;  
  // //n-1 times relaxation 
  // for(int i=1; i < n; i++){


  //   //traverse on entire edge list
  //   for(auto a: adjList){
  //     for(auto b: a.second){
  //       char u = a.first;
  //       char v = b.first;
  //       int wt = b.second;

  //       if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
  //         dist[v] = dist[u]+wt;
  //       }
  //     }
  //   }
  // }
  // //yaha tak shortest dist ban kar ready ho gyi hogi 
  // //check for -ve cycle 
  // //1 time relxation ek bar 
  // bool anyUpdate = false;
  // for(auto a: adjList){
  //     for(auto b: a.second){
  //       char u = a.first;
  //       char v = b.first;
  //       int wt = b.second;

  //       if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
  //         anyUpdate = true;
  //         break;
  //         dist[v-'A'] = dist[u - 'A ']+wt;
  //       }
  //     }
  //   }

  //   if(anyUpdate == true){
  //     cout << "Negative Cycle present" << endl;
  //   }else{
  //     cout << "No Negative cycle present" << endl;
  //   }


void floydWarshallAlgo(int n){

  //create a 2d dist array 
  vector<vector<int>> dist(n, vector<int>(n, 1e9));

  //set 0 in diagonal 
  for(int i=0; i<n; i++){
    dist[i][i] = 0; 
  }

  //khuch weights graph ke andar bhi hai 
  //update dist array accord to that 

  for(auto a: adjList){
    for(auto b: a.second){
      int u = a.first;
      int v = b.first;
      int wt = b.second;
      dist[u][v] = wt;
    }
  }

  //main logic lies here 
  for(int helper = 0; helper < n; helper++){
    for(int src = 0; src < n; src++){
      for(int dest = 0; dest < n; dest++){
         dest[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
      }
    }
  }

  //print the dist arry 
  for(int i = 0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

}

};
int main() {
  // Graph g;
  // g.addEdge('A', 'B', -1, 1);
  // g.addEdge('B', 'E', 2, 1);
  // g.addEdge('E', 'D', -3, 1);
  // g.addEdge('D', 'C', 5, 1);
  // g.addEdge('C', 'A', 4, 1);
  // g.addEdge('B', 'C', 3, 1);
  // g.addEdge('B', 'D', 2, 1);
  // g.addEdge('D', 'B', 1, 1);
  // g.printList();
  // g.bellManFord(5, 'A'); 

  Graph g;
  g.addEdge(0,1 , 3, 1);
   g.addEdge(1,0 , 2, 1);
    g.addEdge(0,3 , 5, 1);
     g.addEdge(1,3 , 4, 1);
      g.addEdge(3,2 , 2, 1);
       g.addEdge(2,1 , 1, 1);
      g.floydWarshallAlgo(4);


  return 0;
}

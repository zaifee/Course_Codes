#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

class Graph{
public:
unordered_map<char , list<pair<char, int> > > adjList;

void addEdge(char u, char v, int wt, bool direction){
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

void bellManFord(int n, int src){
  //dist array 
  vector<int> dist(n, INT_MAX);
  //initial state 
  dist[src] = 0;  
  //n-1 times relaxation 
  for(int i=1; i < n; i++){


    //traverse on entire edge list
    for(auto a: adjList){
      for(auto b: a.second){
        char u = a.first;
        char v = b.first;
        int wt = b.second;

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
          dist[v] = dist[u]+wt;
        }
      }
    }
  }
  //yaha tak shortest dist ban kar ready ho gyi hogi 
  //check for -ve cycle 
  //1 time relxation ek bar 
  bool anyUpdate = false;
  for(auto a: adjList){
      for(auto b: a.second){
        char u = a.first;
        char v = b.first;
        int wt = b.second;

        if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
          anyUpdate = true;
          break;
          dist[v-'A'] = dist[u - 'A ']+wt;
        }
      }
    }

    if(anyUpdate == true){
      cout << "Negative Cycle present" << endl;
    }else{
      cout << "No Negative cycle present" << endl;
    }




}

};
int main() {
  Graph g;
  g.addEdge('A', 'B', -1, 1);
  g.addEdge('B', 'E', 2, 1);
  g.addEdge('E', 'D', -3, 1);
  g.addEdge('D', 'C', 5, 1);
  g.addEdge('C', 'A', 4, 1);
  g.addEdge('B', 'C', 3, 1);
  g.addEdge('B', 'D', 2, 1);
  g.addEdge('D', 'B', 1, 1);
  g.printList();
  g.bellManFord(5, 'A');

  return 0;
}

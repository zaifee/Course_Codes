#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
class Graph{
public:
map<int, list<int> > adjList;

void addEdge(int u, int v, bool direction){
  if(direction == 1){
    adjList[u].push_back(v);
  }
  else{
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

}
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

int main() {
  
  Graph g;
  g.addEdge(0,5, 0);
  g.addEdge(5, 4, 0);
  g.addEdge(4, 3, 0);
  g.addEdge(0, 6, 0);
  g.addEdge(6, 3, 0);
  g.addEdge(0, 1, 0);
  g.addEdge(1, 2, 0);
  g.addEdge(2, 3 ,0);
  // g.printEdge();
  int n = 7;
  int src = 0;
  int dest = 3;
  g.shortestPathBFS(src, dest);

}



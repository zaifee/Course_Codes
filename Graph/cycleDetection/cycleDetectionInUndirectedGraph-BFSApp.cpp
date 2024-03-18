//Detecting cycle using undirected graph -- BFS approach 
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int src, unordered_map<int, bool>& visited, vector<int> adj[]){
    
    queue<int> q;
    
    unordered_map<int,int> parent;

    //initial state 
    
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
      int frontNode = q.front();
      q.pop();

      for(auto nbr: adj[frontNode]){
        if(!visited[nbr]){
          q.push(nbr);
          visited[nbr] = true;
          parent[nbr] = frontNode;
         
        }

       else if(visited[nbr] == true && nbr != parent[frontNode]){
          return true;
        }
      }
    }
    //cycle not present 
    return false;


    }
    bool isCycle(int V, vector<int> adj[]) {
    
        unordered_map<int, bool> visited;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = solve(i, visited, adj);
                if(ans == true)
                    return true;
            }
        }
        return false;
    }
};

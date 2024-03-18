// Function to detect cycle in an undirected graph.
    bool checkCycle(int src, vector<int> adj[],  unordered_map<int, bool>& vis, int parent){
        
       
        vis[src] = true;
        
        
        for(auto &nbr: adj[src]){
            if(nbr == parent)
                continue;
            if(!vis[nbr]){
                bool ans = checkCycle(nbr, adj, vis, src);
                if(ans == true) return true;
            }
            
            //  else if(vis[nbr] == true && nbr != parent)
            //     return true;
                
             else if(vis[nbr] == true && nbr != parent)
                return true;
        }
      
            
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
       unordered_map<int, bool> vis;
       int src = 0;
       for(int i=0; i < V; i++){
           if(!vis[i]){
               int parent = -1;
               bool ans = checkCycle(i, adj, vis, parent);
               if(ans == true) return true;
           }
       }
       return false;
    }

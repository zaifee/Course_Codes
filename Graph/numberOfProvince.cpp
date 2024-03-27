//In this question we have to count the components of graph it may be connected component of disconnected component so for this we can used bfs or dfs.
// below approach is a dfs approach
class Solution {
public:
    void dfs(int src, unordered_map<int, bool>& vis, int n, vector<vector<int>>& isConnected){

        vis[src] = true;

        //node ke nbr haar column me milenge 
        int col = n;
        int row = src;

        for(int nbrIndex = 0; nbrIndex < col; nbrIndex++){
            int nbr = nbrIndex;

            if(/*src != nbr && */ isConnected[row][nbrIndex] == 1){
                  if(!vis[nbr]){
                    dfs(nbr, vis, n, isConnected);
                  }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int count = 0;
        unordered_map<int, bool> vis;

        for(int i=0; i<n; i++){

            if(!vis[i]){
                dfs(i, vis, n, isConnected);
                count++;
            }
        }
        return count;
    }
};

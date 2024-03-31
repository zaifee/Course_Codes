class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<char>> &grid,  map<pair<int, int>, bool> &vis){

        if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1' && vis[{newX, newY}] == false){
            return true;
        }
        else
            return false;
    }
    void bfs(int srcX, int srcY,  map<pair<int, int>, bool> &vis, vector<vector<char>> &grid){

        queue<pair<int, int>> q;
        vis[{srcX, srcY}] = true;
        q.push({srcX, srcY});

        while(!q.empty()){
            pair<int,int> frontNode = q.front();
            q.pop();

            int tempX = frontNode.first;
            int tempY = frontNode.second;

            //explore all four direction 
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];

                if(isSafe(newX, newY, grid, vis)){
                q.push({newX, newY});
                vis[{newX, newY}] = true;
            }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
      queue<pair<int, int>> q;
      map<pair<int, int>, bool>vis; //map use hoga naki unordered map

      int m = grid.size(); 
      int n = grid[0].size(); //no. of columns 
      int count = 0;
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!vis[{i, j}] && grid[i][j] == '1'){
                bfs(i, j, vis, grid);
                count++;
            }
        }
      }
      return count;
    }
};

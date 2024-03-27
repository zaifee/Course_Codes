class Solution {
public:
    typedef pair<int, pair<int, int> > P;
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size(); //rows
        int n = grid[0].size(); //no. of column

        if(m == 0 || n == 0 || grid[0][0] != 0){
            return -1;
        }

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        vector<vector<int> >result(m, vector<int> (n, INT_MAX));
        priority_queue<P, vector<P>, greater<P> > pq; //ye shi declare nhi kari thi

        pq.push({0, {0, 0}});
        result[0][0] = 0; //yaha galti ki thi result me 

        while(!pq.empty()){
            int topNodeDis = pq.top().first;

            pair<int,int> cordinates = pq.top().second;
            int x = cordinates.first;
            int y = cordinates.second;
            pq.pop();
        
            for(auto dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                    
            int dis = 1;
                if(isSafe(x_, y_) && grid[x_][y_] == 0 && topNodeDis + dis < result[x_][y_]){
                    pq.push({topNodeDis+dis, {x_, y_}});
                    result[x_][y_] = topNodeDis + dis; //yaha grid me update kar raha tha
                }
            }

            

        }
        if(result[m-1][n-1] == INT_MAX)
                return -1;
            else
                return result[m-1][n-1]+1;
    }
};

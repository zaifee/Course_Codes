class Solution {
public:
    bool isSafe(int newX, int newY, vector<vector<int>>& temp){
        if(newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1){
            return true;
        }else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        // pair<int, int> => represent coordinates 
        //second member represent time 
        queue<pair<pair<int, int>, int > > q; 
        vector<vector<int>> temp = grid; //making a copy so that we did't change the actual one
        int minTime =  0;

        int n = grid.size();
        int m = grid[0].size();

// Initial state of bfs
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(temp[i][j] == 2){
                //Pushing everyNode which is 2 as there time is zero
                    q.push({{i, j}, 0});
                }
            }
        }

        //bfs logic 
        while(!q.empty()){
            pair<pair<int, int>, int> frontNodePair = q.front();
            q.pop(); //pop karna bhul gya tha

            auto frontNodeCoordinate = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;

            int tempX = frontNodeCoordinate.first;
            int tempY = frontNodeCoordinate.second;


            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0 , 1, 0, -1};

            for(int i=0; i<4; i++){
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];

                if(isSafe(newX, newY, temp)){
                    q.push({{newX, newY}, frontNodeTime+1});
//jab ek new time mil rha hai isTime me dhayan rakho kya yhi jo time nikla wohi ans to nhi hai
                    minTime = max(minTime, frontNodeTime+1);
                    //mark rotten that tomato also 
                    temp[newX][newY] = 2; //we mark rotten with 2
                }
            }

        }

        //yaha tak sare orange rotten ho gye honge. Ab me ye check karna chahta ho sab orange rotten ho gye ya nhi 
        //so travel karo 
        // int freshOrangeCount = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(temp[i][j] == 1){
                    return -1;
                }
            }
        }

        // if(freshOrangeCount == 0){
        //     return minTime;
        // }else{
        //     return -1;
        // }
        return minTime;
    }
};

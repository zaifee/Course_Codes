class Solution {
public:
    typedef pair<int, pair<int, int> > P;
                                    //top    down    //left   //right
    vector<vector<int> > directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size(); //coln me mistake ki

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < m &&  y >= 0 && y < n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        
        priority_queue<P, vector<P>, greater<P>> pq;

        //Initial state
        

        pq.push({0,{0, 0}});
        result[0][0] = 0;
        
        while(!pq.empty()){
            int diff = pq.top().first;

            pair<int, int> cordi = pq.top().second;
            pq.pop();

            int x = cordi.first;
            int y = cordi.second;

            for(auto &dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
               
                if(isSafe(x_, y_)){
                    // int absDiff = abs((heights[x][y] - heights[x_][y_]));
                    // int maxDiff = max(maxDiff, absDiff);

                    int newDiff = max(diff, abs(heights[x][y]- heights[x_][y_])); //yaha galti ki 

                    if(result[x_][y_] > newDiff){
                        result[x_][y_] = newDiff;
                        pq.push({result[x_][y_], {x_, y_}}); //yaha galti ki
                    }
                }
            }

        }
        return result[m-1][n-1];
    }
};

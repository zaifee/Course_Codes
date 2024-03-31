// class Solution {
// public:
//     bool isSafe(int newX, int newY, int sr, int sc, map<pair<int, int>, bool>& vis,vector<vector<int>>& ans, int oldColor){

//         if(newX >= 0 && newY >= 0 && newX < ans.size() && newY < ans[0].size() && ans[newX][newY] == oldColor && vis[{newX, newY}] == false){
//             return true;
//         }
//        else{
//         return false;
//        }

// /*
// ans[newX][newY] == oldColor //hmmne pehle hi ans me oldcolor store kar rakha hai to agar hamare ans me oldColor hai to hi hmm update kar pate hai nhi to nhi kar pate 
//  && vis[{newX, newY}] == false){


// */
//     }
//     void dfs(int oldColor, int newColor, map<pair<int, int>, bool> &vis,vector<vector<int>>& image, int sr, int sc, vector<vector<int>>& ans){
//         vis[{sr, sc}] =  1;
//         ans[sr][sc] = newColor;
//         // cout << "ans sr and sc " << ans[sr][sc] << endl;

//         int dx[] = {-1, 0, 1, 0};
//         int dy[] = {0,1, 0, -1};

//         for(int i=0; i<4; i++){
//             int newX = sr + dx[i];
//             // cout << "newX" << newX << endl;
//             int newY = sc + dy[i];
//             // cout << "newY" << newY << endl;
//             if(isSafe(newX, newY, sr, sc, vis, ans, oldColor)){
//                 //yaha galti ki thi call me sr,sc ki jagah ab newX, newY pass hoga
//                 dfs(oldColor, newColor, vis, image, newX, newY, ans);
//             }
//         }

//     }
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         vector<vector<int>> ans = image;
//         map<pair<int, int> , bool> vis;
//         int oldColor = image[sr][sc];
//         int newColor = color;

//         //here we are not running loop bcz we don't want to do processing on every component of graph or node 
//         dfs(oldColor, newColor, vis, image, sr, sc, ans);
//         return ans;
//     }
// };

//In this code I'm not using visited map without visited

class Solution {
public:
    bool isSafe(int newX, int newY, int sr, int sc,vector<vector<int>>& ans, int oldColor){

        if(newX >= 0 && newY >= 0 && newX < ans.size() && newY < ans[0].size() && ans[newX][newY] == oldColor){
            return true;
        }
       else{
        return false;
       }

/*
ans[newX][newY] == oldColor //hmmne pehle hi ans me oldcolor store kar rakha hai to agar hamare ans me oldColor hai to hi hmm update kar pate hai nhi to nhi kar pate 
 && vis[{newX, newY}] == false){


*/
    }
    void dfs(int oldColor, int newColor ,vector<vector<int>>& image, int sr, int sc, vector<vector<int>>& ans){
        
        ans[sr][sc] = newColor;
        // cout << "ans sr and sc " << ans[sr][sc] << endl;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0,1, 0, -1};

        for(int i=0; i<4; i++){
            int newX = sr + dx[i];
            // cout << "newX" << newX << endl;
            int newY = sc + dy[i];
            // cout << "newY" << newY << endl;
            if(isSafe(newX, newY, sr, sc , ans, oldColor)){
                //yaha galti ki thi call me sr,sc ki jagah ab newX, newY pass hoga
                dfs(oldColor, newColor , image, newX, newY, ans);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        
        int oldColor = image[sr][sc];
        int newColor = color;

        //bcz hmmne visited map hataya so, incase of same old color and newColor hmme ek aur case handle karna padega
        if(oldColor == newColor){
            return ans;
        }

        //here we are not running loop bcz we don't want to do processing on every component of graph or node 
        dfs(oldColor, newColor,  image, sr, sc, ans);
        return ans;
    }
};

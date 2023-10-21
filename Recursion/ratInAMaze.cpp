

#include <iostream>
#include <vector>
using namespace std;
//a function that handle all the below possiblities 
//3 edge case hai 
    //path closed 
    //outof bound 
    //check it is possible it is already visited -- making a fun to handle to handle all these cases
bool isSafe(int srcx, int srcy, int newx, int newy,int maze[][4], int row, int col, vector<vector<bool> >&visited){
    
    //path closed + outof bound 
    if(
        (newx >= 0 && newx < row) && (newy >= 0 && newy < col)  && maze[srcx][srcy] == 1 
      && visited[newx][newy] = false;
    ){
    return true;
    }
    
    else{
        return false;
    }
}




void printAllPath(int maze, int row, int col, int srcx, int srcy, string &output, vector<vector<bool> >&visited){
    
    //destination x and destination y --> des[row-1] or dest[col-1]; 
    
    if(srcx == row-1 && srcy == col-1){
        //reached destination 
        cout << output << endl;
        return;
    }
    
    //1 case solve karo baki rec dekh lega 
    
    
    //order of up, down , right, and left doesn't matter 
    
    // up 
    //3 edge case hai 
    //path closed 
    //outof bound 
    //check it is possible it is already visited -- making a fun to handle to handle all these cases 
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(maze, srcx, srcy, newx, newy, row, col, visited)){
        //mark visited 
        visited[newx][newy] = true;
        //call recursi 
        printAllPath(maze, row, col, newx, newy, output + "U", visited)
        //backtracking 
        isited[newx][newy] = false;
        
        
    }
    
    
    
    
    //down 
    
     int newx = srcx+1;
    int newy = srcy;
    if(isSafe(maze, srcx, srcy, newx, newy, row, col, visited)){
        //mark visited 
        visited[newx][newy] = true;
        //call recursi 
        printAllPath(maze, row, col, newx, newy, output + "D", visited)
        //backtracking 
        isited[newx][newy] = false;
        
        
    }
    
    
    
    //right 
     int newx = srcx;
    int newy = srcy+1;
    if(isSafe(maze, srcx, srcy, newx, newy, row, col, visited)){
        //mark visited 
        visited[newx][newy] = true;
        //call recursi 
        printAllPath(maze, row, col, newx, newy, output + "R", visited)
        //backtracking 
        isited[newx][newy] = false;
        
        
    }
    
    
    
    //left 
     int newx = srcx;
    int newy = srcy-1;
    if(isSafe(maze, srcx, srcy, newx, newy, row, col, visited)){
        //mark visited 
        visited[newx][newy] = true;
        //call recursi 
        printAllPath(maze, row, col, newx, newy, output + "L", visited)
        //backtracking 
        isited[newx][newy] = false;
        
        
    }
    
    
    
    
    
    
    
    
    
}



int main()
{
   int maze[4][4] = {
      {1,0,0,0},
      {1,1,0,1},
      {1,1,0,1},
      {1,1,1,1}
      
   };
   
   int row = 4, col=4;
   int srcx = 0;
   int srcy = 0;
   string output = "";
   
//   creating a 2d array  -- 
vector<vector<bool> >visited(row, vector<bool>(col, false));
   if(maze[0][0] == 0){
       cout << "No Path Exist " << endl;
   }
   else{
   visited[srcx][srcy] = true;
   printAllPath(maze, row, col, srcx, srcy, output);
   }
   
   

    return 0;
}

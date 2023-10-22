

#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int srcx, int srcy, int maze[][4],int newx, int newy, int row, int col,vector<vector<bool> >&visited){
    
    if( 
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy] == 1 &&
        visited[newx][newy] == false //pichli bar yaha galti kari thi 
        
        )
        {
            return true;
        }
        else{
            return false;
        }
    
}
void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string &output,  vector<vector<bool> >&visited){
    
    //base case 
    if(srcx == row-1 && srcy == col-1){
        //reached at the destination so print ouput
        cout << output << endl;
       
        return;
    }
    
    
    //handle three cases 
    //outofbound
    //open path indicating by 1 
    //mark visited -- isSafe
    
    
    //UP 
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(srcx,srcy,maze, newx, newy, row, col,visited)){
        
        //mark visised 
        visited[newx][newy] = true;
        
        //recusive call 
        output.push_back('U');
        printAllPath(maze, row, col, srcx, srcy, output, visited);
        
        //backtracking 
        output.pop_back();
        visited[newx][newy] = false;
       
    }
    
    //down 
   
     newx = srcx+1;
     newy = srcy;
    if(isSafe(srcx,srcy,maze, newx, newy, row, col,visited)){
        
        //mark visised 
        visited[newx][newy] = true;
        
        //recusive call 
        output.push_back('D');
        printAllPath(maze, row, col, srcx, srcy, output, visited);
        
        //backtracking 
        output.pop_back();
        visited[newx][newy] = false;
       
    }
    
    //left 
    
     newx = srcx;
     newy = srcy-1;
    if(isSafe(srcx,srcy,maze, newx, newy, row, col,visited)){
        
        //mark visised 
        visited[newx][newy] = true;
        
        //recusive call 
        output.push_back('L');
        printAllPath(maze, row, col, srcx, srcy, output, visited);
        
        //backtracking 
        output.pop_back();
        visited[newx][newy] = false;
       
    }
    
    //right 
     newx = srcx;
     newy = srcy+1;
    if(isSafe(srcx,srcy,maze, newx, newy, row, col,visited)){
        
        //mark visised 
        visited[newx][newy] = true;
        
        //recusive call 
        output.push_back('R');
        printAllPath(maze, row, col, srcx, srcy, output, visited);
        
        //backtracking 
        output.pop_back();
        visited[newx][newy] = false;
       
    }
    
    
    
    
}



int main()
{
   int maze[4][4] = {
       {1,0,0,0},
       {1,1,0,0},
       {1,1,1,0},
       {1,1,1,1}
      
   };
   int row = 4, col = 4;
   int srcx = 0;
   int srcy = 0;
   vector<vector<bool> >visited(row, vector<bool>(col, false));
   string output = "";
   if(maze[0][0] == 0){  //yaha galti ki
       cout << "Not Path Exist " << endl;
   }else{
       visited[srcx][srcy] = true;
     printAllPath(maze, row, col, srcx, srcy,output, visited);
   }
   
    return 0;
   
   }
   


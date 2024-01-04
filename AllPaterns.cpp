#include <iostream>

using namespace std;

int main()

{
  
    int n;
    cin>>n;
/*
* 
* * 
* * * 
* * * * 
* * * * * 

 for(int row=0; row<n; row++){
        for(int col=0; col<row+1; col++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    
*/
/*
* * * * * 
* * * * 
* * * 
* * 
* 


 for(int row=0; row<n; row++){
        for(int col=0; col<n-row; col++){
            cout << "*" << " ";
        }
        cout << endl;
    }

*/
/*
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 

for(int row=1; row<=n; row++){
        for(int col=1; col<row+1; col++){
            cout << col << " ";
        }
        cout << endl;
    }

*/
/*
for n = 5
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 
for(int row=0; row<n; row++){
        for(int col=1; col<n-row; col++){
            cout << col+1 << " ";
        }
        cout << endl;
    }

*/

//hollow Rectangle 
/*
****
*  *
*  *
****



for(int i=1; i<=4; i++){
  for(int j=1; j<=4; j++){
    if(i == 1 || i == 4){
      cout << "*";
    }
    else{
      if(j == 1 || j == 4){
        cout << "*";
      }
      else{
        cout << " ";
      }
    }
  }
  cout << endl;
}
  */

 //full pyramid 
 /*
 for n = 10;
         *
        * * 
       * * * 
      * * * * 
     * * * * * 
    * * * * * * 
   * * * * * * * 
  * * * * * * * * 
 * * * * * * * * * 
* * * * * * * * * * 
 for(int row=0; row<n; row++){
  for(int col=0; col<n-row-1; col++){
         cout << " ";
  }
  for(int col=0; col<row+1; col++){
    cout << "* "; //star ke sath space add karo nhi to galti hogi
  }
  cout << endl;
 }
   */

// inverted full pramid 
/*
* * * * 
 * * * 
  * * 
   * 
for(int row=0; row<n; row++){

for(int col=0; col<row; col++){ //iski condtion me galti ki thi
    cout << " ";
  }

  for(int col=0; col<n-row; col++){
    cout << "* ";  //star ke baad space galti hogi
  }
  
  cout <<endl;

}
*/

//Diamond Pattern -- combination of (full pyramid[code] + Inverted pyramid[code]); 
/*
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
* * * * * 
 * * * * 
  * * * 
   * * 
    * 

for(int row=0; row<n; row++){
  for(int col=0; col<n-row-1; col++){
    cout << " "; //spaces ke liye
  }
  for(int col=0; col<row+1; col++){
    cout <<"* ";
  }
  cout << endl;
  }

//  + inverted pyramid 
for(int row=0; row<n; row++){
  for(int col=0; col<row; col++){
       cout << " ";
  }
  for(int col=0; col<n-row; col++){
    cout << "* ";
  }
  cout << endl;
}
*/

//hollow full pyramid 
/*
    * 
   * * 
  *   * 
 *     * 
*       * 

for(int row=0; row<n; row++){
  for(int col=0; col<n-row-1; col++){
    cout <<" ";
  }
  for(int col=0; col < row+1; col++){
    if(col == 0 || col == row + 1 - 1){ //sign bhi dhiyan rakhyo
      cout << "* ";
    }else{
       cout << "  ";  //yaha galti ki 2 spaces dene hai
    }
  }
  cout << endl;
}
*/

/*
*       * 
 *     * 
  *   * 
   * * 
    * 

for(int row=0; row<n; row++){
  for(int col=0; col<row; col++){
    cout << " ";
  }
  int totalCols = n-row;
  for(int col=0; col<totalCols; col++){
     if(col == 0 || col == totalCols-1){
       cout << "* ";
     }
     else{
      cout << "  "; //yaha bhi do spaces aayege galti ki thi 
     }
  }
  cout << endl;
}
*/


    
    return 0;
}

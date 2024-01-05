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

//Day - 2-------------------------- Patterns Revision:------------------------
#include <iostream>
using namespace std;

int main() {
   int n; 
   cin >> n;

   /*
**** ****
***   ***
**     **
*       *
*       *
**     **
***   ***
**** ****


   for(int row=0; row<n; row++){
    for(int col=0; col<n-row; col++){
      cout << "*";
    }
   
  //  2*row+1 means its a odd number
   for(int col =0; col<2*row+1; col++){
     cout << " ";
   }
  //  stars
  for(int col=0; col<n-row; col++){
      cout << "*";
    }
    cout << endl;
   }
//lower pyramid 
//stars
for(int row=0; row<n; row++){
  for(int col=0; col<row+1; col++){
       cout << "*";
  }

 //spaces
  for(int col=0; col<2*n-2*row-1; col++){
    cout << " ";
  }

//  stars 
for(int col=0; col<row+1; col++){
  cout << "*";
}
 cout << endl;
}

*/

/*
1
2*2
3*3*3
4*4*4*4

for(int row=0; row<n; row++){
  for(int col=0; col<2*row+1; col++){
     if(col % 2 == 1){
       cout << "*";
     }
     else{
      cout<<row+1;
     }
  }
  cout << endl;
}

*/
/*
1
2*2
3*3*3
4*4*4*4
3*3*3
2*2
1


for(int row=0; row<n; row++){
  for(int col=0; col<2*row+1; col++){
     if(col % 2 == 1){
       cout << "*";
     }
     else{
      cout<<row+1;
     }
  }
  cout << endl;
}

//Second half
for(int row=n-2; row>=0; row--){
  for(int col=0; col<2*row+1; col++){
      if(col%2 == 1){
         cout<<"*";
      }
      else{
        cout<<row+1;
      }
  }
  cout << endl;
}

*/

/*
******
*
*
*
*
*

**********
*       *
*      *
*     *
*    *
*   *
*  *
* *
**
*

for(int row=0; row<n; row++){
  for(int col=0; col<n-row; col++){
    if(row == 0 || row == n-1){
      cout << "*";
    }
    else{
      if(col == 0 || col == n-row-1){ //yaha galti kar raha tha col ki condi me
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
/*
A 
A B A 
A B C B A 
A B C D C B A 
A B C D E D C B A 


 for(int row=0; row<n; row++){
  char ch;
  for(int col=0; col<row+1; col++){
    int number = col+1;
     ch = number + 'A' - 1; //created a mapping 
     cout << ch << " ";
  }
  //jab tak reverse print karenge tab tak a nhi aayega 
  for(char alphabet = ch; ch > 'A'; ch--){
     alphabet--; //bcz hmme decrement karke print karna hai
     cout << alphabet << " ";
  }
 cout << endl;

 }
 */
/*
1
121
12321
1234321
123454321

 for(int row=0; row<n; row++){
  int count = 1;
  for(int col=1; col<=row+1; col++){
    cout << col << " ";

  }
  for(int col=row; col>0; col--){
    cout<<col<<" ";
  }
  
  cout << endl;
 }
 */
 /*
 1 2 3 4 5 
2 3 4 5 
3 4 5 
4 5 
5 

int count = 1;
 for(int row=0; row<n; row++){
  
  for(int col=row+1; col<=n; col++){
        cout<<col<<" ";
  }
  cout << endl;
 }
*/
/*
* * * * * * * * 1 
* * * * * * * 2 * 2 * * 
* * * * * * 3 * 3 * 3 * * * * 
* * * * * 4 * 4 * 4 * 4 * * * * * * 
* * * * 5 * 5 * 5 * 5 * 5 * * * * * * * * 

for(int row=0; row<n; row++){
  for(int col=0; col<2*n-row-2; col++){
     cout << "*" << " ";
  }
  for(int col=0; col<2*row+1; col++){
    if(col%2 == 1){
       cout <<"*"<<" ";
    }
    else{
       cout<<row+1<<" ";
    }
  }
  //print right half 
  for(int col=0; col<2*row; col++){
     cout << "* ";
  }

  


  cout << endl;
}

*/


  
 return 0;
}


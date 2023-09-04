#include <iostream>
using namespace std;

int main() {
// A shape
for(int i=0; i<4; i++){
  for(int j=0; j<7; j++){
    if(i + j == 3 || j-i == 3){
         cout << "*";
    }else{
    cout << " ";
    }
  }
  cout << endl;
}








/*
// Diamond Pattern 
// Pattern with spaces pyramid + Inverted pyramid with spaces 
int k,n;
cin >> n;
for(int i=0; i<n; i++){
  k = 1;
  for(int j=0; j<2*n-1; j++){
    if(j >= 3-i && j <= 3+i && k ){
      cout << "*";
       k=0;
    }else{
      cout << " ";
      k = 1;
    }
  }
  cout << endl;
}

for(int i=0; i<4; i++){
  k = 1;
  for(int j=0; j<7; j++){
    if(j >= i && j <= 6-i && k){
      cout << "*";
      k = 0;
    }else{
     cout << " ";
     k = 1;
    }
  }
  cout << endl;
}
 

// Inverted pyramid with spaces between them
int k;
for(int i=0; i<4; i++){
  k = 1;
  for(int j=0; j<7; j++){
    if(j >= i && j <= 6-i && k){
      cout << "*";
      k = 0;
    }else{
     cout << " ";
     k = 1;
    }
  }
  cout << endl;
}
//pattern with spaces pyramid

int n, k;
  cin >> n;
for(int i=0; i<6; i++){
    k = 1;
  for(int j=0; j<10; j++){
    if(j >= 6-i && j <= 4+i && k){
      cout << "*";
      k = 0;
    }else{
      cout << " ";
      k = 1;
    }
  }
  cout << endl;
}

//hollow full pyramid
int n;
cin >> n;
for(int i=0; i<6; i++){
  for(int j=0; j<11; j++){
    if(i+j == 5 || j-i == 5 || i==5){
      cout << "*";
    }else{
      cout << " ";
    }
  }
  cout << endl;
}







// Full pyramid
int n,
cin >> n;
for(int i=0; i<n; i++){
  // generlaise formula for column 2*n-1
  for(int j=0; j<2*n-1; j++){
    
    if(j >= n-i && j <= n+i && k){
      cout << "*";
      
    }else{
      cout << " ";
      
    }
  }
  cout << endl;
}


// hollow inverted half pyramid;
// we are using n-i-1 formula to print at last coln
 int n;
  cin>>n;
  
for(int i=0; i<n; i++){
  for(int j=0; j<n; j++){
    if(i == 0 || j == 0 || j == n-i-1){
      cout << "*";
    }else{
      cout << " ";
    }
    
  }
  cout << endl;
}







  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i; j++){
      cout << j+1 << " ";
    }
    cout << endl;
  }
*/

  return 0;
}

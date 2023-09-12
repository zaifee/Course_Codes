#include<iostream>
using namespace std;
void areaCircle(int r){
    float area = 3.14 * r * r;
    cout << "Your Area of circle is: " << area << endl;
    
}

void evenAndOdd(int n){
    if(n & 1 == 0){  //last bit is 1 then odd and if the last bit is 0 then it is even
        cout << "Even";
    }
    else{
        cout << "Me to Odd ho bata tu bata kya hai";
    }
    cout << endl;
}


void findFactorial(int n){
    int fact = 1;
    for(int i=1; i<=n; i++){
        fact = fact * i;
    }
    cout << "Your fact of " << n << " is " << fact << endl;
}
bool PrintAllPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i == 0){
           return true;
        }else{
            return false;
        }
    }
}



int main(){
 
    areaCircle(4);
    evenAndOdd(5);
    
    findFactorial(5);
  int ans = PrintAllPrime(6);
  if(ans){
      for(int i=0; i<ans; i++){
          cout << i <<" ";
      }
  }else{
      cout << "Prime Number not exist";
  }
    
    return 0;
}

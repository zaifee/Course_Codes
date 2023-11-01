#include <iostream>

using namespace std;

int main()
{
 int n;
 cin >> n;
 int fact = 1;
 for(int i=1; i<=n; i++){
     fact = fact * i;  //1*1 = 1*2 = 2*3 = 6; 6*4= 24; 24*5=120
 }
 cout << fact << endl;
    
    
    return 0;
}

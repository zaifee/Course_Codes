

#include <iostream>

using namespace std;

//count dearrangement of element 
int countDearrangement(int n){
    
    //base case 
    
    if(n <= 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    //n-1 when I placed just 1st element in the array 
    // now two cases will be there  -- 2 cases 
    
     //1 case
    //I placed 1st elemnt at i the position and I palced the ith position element at 1 element position now total elements
    //that remains uplaced that now total elements placed 2 so total elements uplaced i.e n-2; 
    
    
    //2 case 
    // I placed 1st postion element at ith position but not placed ith element at 1 position now i can come anywhre
    // so total elements remained that i.e one element is only placed = f(n-1)
    
    
    
    int ans = (n-1)*(countDearrangement(n-2)+countDearrangement(n-1));
    return ans;
}


int main()
{
   
   
   int n = 4;
   
 int ans = countDearrangement(n);
  cout << "No.of dearrangement of is : " << ans << endl;
   
   

    return 0;
}

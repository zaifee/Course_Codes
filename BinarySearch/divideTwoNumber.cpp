//search space wali game
#include <iostream>
using namespace std;
int getQuotient(int divisor, int divident){
  int s= 0;
  int e = divident;
  int ans = -1;
  while(s <= e){
    int mid = s + (e-s)/2;

    if(mid * divisor == divident){
      return mid;
    }else if(mid * divisor < divident){
      //store in ans , and right me chle jao
      ans = mid;
      s = mid+1;
    }else{
      e = mid-1;
    }
  }
  return ans;

}
int main() {
  int divisor = 7;
  int divident = 42;

  int ans = getQuotient(divisor, divident);

  cout << "Your Answer is : " << ans << endl;

  return 0;
}

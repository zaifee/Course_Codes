// Extreme Print in an array
#include <iostream>
#include <vector>
using namespace std;
void findReverse(vector<int> arr){
    //using two pointers approach
    int s = 0;
    int e = arr.size()-1;
    while(s <= e){
        cout << arr[s] << " ";
        cout << arr[e] << " ";
        s++;
        e--;
    }

}
int main()
{
   vector<int> arr{10,20,30,40,50,60};
   findReverse(arr);
    return 0;
}

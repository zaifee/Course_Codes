#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
void printArray(vector<int>& arr){
  for(int i=0; i<arr.size(); i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
// Comparator ka type bool hota hai 
bool myComp(int &a, int &b){
  // return a < b; //increasing order me sort karenge 
  return a > b; //dec order me sort kar rahe honge
}

void printVectorArray(vector<vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        vector<int>& temp = arr[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
}


bool  myCompOfVector(vector<int>&a, vector<int>&b){
    // return a[0] < b[0]; //0 based sorting in increasing order 
    return a[1] < b[1];
}




int main() {
  // vector<int>v{22,11,55,44,33};
  // sort(v.begin(), v.end(), myComp);
  // printArray(v);

  vector<vector<int> > v;
  int n;
  cout << "Enter the size of Vector " << endl;
  cin >> n;
  for(int i=0; i<n; i++){
    vector<int>temp;
    int a, b;
    cin >> a >> b;
    temp.push_back(a);
    temp.push_back(b);
    //pusing vector inside another vector
    v.push_back(temp);
  }
  
  
  cout << "Printing the Before sorting " << endl;
  printVectorArray(v);
//   sort(v.begin(), v.end()); //this function work 0 based indexing and it is the impl merger+quick+heap sort
  sort(v.begin(), v.end(), myCompOfVector);
  cout << "Printing after sorting " << endl;
  printVectorArray(v);


  return 0;
}

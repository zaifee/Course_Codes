#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string,int>mpp;
  pair<string,int>p = make_pair("Mohd", 24);

  pair<string,int>q("nawaz", 23);
  
  pair<string,int>r;
  q.first = "hello";
  q.second = 5;

  mpp.insert(p);
  mpp.insert(q);
  mpp.insert(r);
  cout << "size of the Map is: " << mpp.size() << endl;

  //Access 
  cout << mpp.at("nawaz") << endl;
  cout << mpp["nawaz"] << endl;

  return 0;
}

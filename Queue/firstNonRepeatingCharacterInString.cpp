#include <iostream>
#include <queue>
using namespace std;

int main() {

  string str = "ababc";
  queue<char>q; //yaha galti ki 

  int freq[26] = {0}; //freq array to map the elements

  for(int i=0; i<str.length(); i++){
    char ch = str[i];
    freq[ch-'a']++; //character ko number se map kar diya
    q.push(ch);

  
  //Answer find out karlo 
  while(!q.empty()){
    char frontCharacter = q.front(); //yaha galti ki front character me

    if(freq[frontCharacter-'a'] > 1){
      //count se zyada hai tu repeating charater hai
      q.pop();
    }
    else{
      // == 1 wala case hoga 
      // yehi answer hai 
      cout << frontCharacter << " -> ";
      break;
    }
}
  
   if(q.empty()){
    //koi answer nhi nikla 
    cout << "#" << " ";
   }
}
  return 0;
}

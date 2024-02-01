class Info{
public:
char data;
int count;

Info(char ch, int cnt): data(ch), count(cnt){};

};
class compare{
public:
bool operator()(Info a, Info b){
    return a.count < b.count;
}

};

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch-'a']++; //freq map kara di;
        }

        //maxHeap 
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all the characters into the heap where freq of element > 0 
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                 Info temp(i+'a', freq[i]);   //obj bana diya aur usme char and count push kar diya
                //  temp.data = i+'a';
                //  temp.count = freq[i];
                maxHeap.push(temp);
            }
        }
        string ans = "";
     
       while(maxHeap.size() > 1){
           Info first = maxHeap.top();
           maxHeap.pop();

           Info second = maxHeap.top();
           maxHeap.pop();
           //dono ek sath isliye kar rhae hai taki side by side character na aaye 

           ans.push_back(first.data);
           first.count--;

           ans.push_back(second.data);
           second.count--;

        //ab agar unki freq bachi hoi hai to push kardo 
         if(first.count > 0){
             maxHeap.push(first);
         }
         if(second.count > 0){
             maxHeap.push(second);
         }

       }

    //    if single element bacha hai to alag se handle karlo 
      if(maxHeap.size() == 1){
          Info first = maxHeap.top();
          maxHeap.pop();

          ans.push_back(first.data);
          first.count--;

          if(first.count != 0){
              //answer not possible 
              return "";
          }


      }
      return ans;

        
    }
};

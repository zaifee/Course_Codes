class Solution {
public:
    string reorganizeString(string s) {
      typedef pair<int, char>P;

      int n = s.length();

    //   step1: store the freq of char 
     vector<int>count(26, 0); //26 character ki freq 
     for(char &ch: s){
         count[ch-'a']++;

         //if freq > (n+1)/2 string bann not possible 
         if(count[ch-'a'] > (n+1)/2) return "";
     }

    //  step2: push the freq vector in the maxheap with their int value 
    priority_queue<P, vector<P>> pq;
    for(char ch = 'a'; ch <= 'z'; ch++){
        if(count[ch-'a'] > 0){
            pq.push({count[ch-'a'], ch});
        }
    }

    string res = "";

    while(pq.size() >= 2){
        auto P1 = pq.top();
        pq.pop();

        auto P2 = pq.top();
        pq.pop();

        //push in res 
        res.push_back(P1.second); P1.first--; //second string hai isliye push kar rahe 
        res.push_back(P2.second); P2.first--;

        if(P1.first > 0){
            pq.push(P1);
        }

         if(P2.first > 0){   //Mistake kari thi ye count[ch-'a']
            pq.push(P2);
        }

    }

    if(!pq.empty()){
        res.push_back(pq.top().second);
    }
    return res;

    }
};

class Solution {
public:
    string reorganizeString(string s) {
    

      int n = s.length();

    //   step1: store the freq of char 
     vector<int>count(26, 0); //26 character ki freq 
    int maxFreq = 0; //ye no ke liye 
    int maxFreqCh; //ye character 

     for(char &ch: s){
         count[ch-'a']++;

         if(count[ch-'a'] > maxFreq){
             maxFreq = count[ch-'a'];
             maxFreqCh = ch;

         }

         //if freq > (n+1)/2 string bann not possible 
         if(count[ch-'a'] > (n+1)/2) return "";
     }

     //now place the maxfreq character first 
     string result = s;
     int i = 0;
     while(count[maxFreqCh - 'a'] != 0){
         result[i] = maxFreqCh;
         i += 2;
         count[maxFreqCh-'a']--;
     }

     //now place the rest of the characters to the empty slots 
     for(char ch = 'a'; ch <= 'z'; ch++){
      while(count[ch-'a'] > 0){
         if(i >= n){
             i = 1;

             result[i] = ch;
             i += 2;
             count[ch-'a']--;
         }
     }
     }
     return result;

    
    }
};

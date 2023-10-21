class Solution {
public:
  void removeOcc(string &s, string &part){
     
     int found = s.find(part); //it will return part index 
     if(s.find(part) != string::npos){
      //part exisit in the string 
        //remove character -- making two string left + right 
        string left_part = s.substr(0, found);
        string right_part = s.substr(found+part.size(), s.size());

        s  = left_part + right_part;  // 1 part solve ho gya 

        removeOcc(s, part);

}



  }
    string removeOccurrences(string s, string part) {
        
        removeOcc(s, part);
        return s;
       
    }
};

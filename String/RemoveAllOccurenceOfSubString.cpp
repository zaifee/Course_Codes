class Solution {
public:
    string removeOccurrences(string s, string part) {
        //in this question first we have to find the substring and then 
        // we have to remove those substring from the given string 
        while(s.find(part) != string::npos){
            //removing the substring from the given string
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

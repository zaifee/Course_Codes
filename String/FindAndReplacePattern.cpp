class Solution {
public:
void createMapping(string& str){ //by refernce pass karyo bhai galti kari thi yaha
    char start = 'a';
    char mapping[280] = {0};
    for(auto ch: str){
        mapping[ch] = start;
        start++;
    }
    //update the string 
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        str[i] = mapping[ch];
    }
}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        //create mapping of pattern 1st 
        createMapping(pattern);

        //creating mapping of words 
        for(auto s: words){
            string tempString = s;

            createMapping(tempString);

            //now comparing both word and pattern mapping if both match then pushing into the ans 
            if(tempString == pattern){
                ans.push_back(s);
            }
        }
        return ans;

    }
};

class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        char mapping[280] = {0};
        for(auto ch: key){
            
 //here we initializaing with zero bcz if the same 
//char is already mapped then we did not mapped another char we used earlier mapping value so 0 help here 
            if(ch != ' ' &&  mapping[ch] == 0){
            mapping[ch] = start;
            start++;
            }
        }

        //decoding the mesage
        string ans;
        for(auto ch: message){
            //if space is there insert space 
            if(ch == ' '){
                ans.push_back(' ');
            }else{
            int decodingMessage = mapping[ch];
            ans.push_back(decodingMessage);
            }
        }
        return ans;
    }
};



class Solution {
public:
  void buildAns(stack<string>&s, string &ans){
    if(s.empty()){
        return;
    }
     string minPath = s.top(); s.pop();
      buildAns(s, ans);
      ans += minPath;
  }



    string simplifyPath(string path) {
        stack<string>s;
        

        int i=0;
        while(i < path.size()){
            int start = i;
            int end = i + 1;

            while(end < path.size() && path[end] != '/'){  //yaha galti ki
                ++end; //ignore backslah at the end
            }

            string minPath = path.substr(start, end-start);
            cout << minPath << endl;
             i = end; //update the start pointer 
             if(minPath == "/" || minPath == "/."){ //yaha galti ki && ki jagah || aayega
                 continue;
             }
             if(minPath != "/.."){
                 s.push(minPath);  //agar /.. hoga to pop karna hota hai
             }
             else if(!s.empty()){  //pop jabhi kar pao ga jab stack empty nhi hoga 
                 s.pop(); 
             }
        }
        //suppose stack khatm ho gyi 
        string ans = s.empty() ? "/" : "";
        buildAns(s, ans);

        return ans;
    }
};

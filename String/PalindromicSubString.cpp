class Solution {
public:
    int expand(string s, int i, int j){
        int count = 0;
        while(i >=0 && j < s.length() && s[i] == s[j]){
                count++;
                i--;
                j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        //using two pointers expand wala logic in even and odd case
        int totalCount = 0;
        for(int center=0; center<s.length(); center++){

            //odd
            int oddcase = expand(s, center, center);

            //even
            int evencase = expand(s, center, center+1);

            //totalcount 
            totalCount = totalCount+oddcase+evencase;
        }
        return totalCount;
    }
};

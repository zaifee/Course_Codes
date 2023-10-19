//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        if(n == 0) return 0;
        
        //cut karte hoe negative no aagye 
        if(n < 0) return INT_MIN;
// x ka part cut karlo baki recursion sambhal lega
        int opt1 = 1 + maximizeTheCuts(n-x, x, y, z);
        
// y ka part cut karlo baki recursion sambhal lega
        int opt2 = 1 + maximizeTheCuts(n-y,x, y, z);
        
 // z ka part cut karlo baki recursion sambhal lega
        int opt3 = 1 + maximizeTheCuts(n-z,x, y, z);
        
        int finalAns = max(opt1, max(opt2, opt3));
        return finalAns;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends

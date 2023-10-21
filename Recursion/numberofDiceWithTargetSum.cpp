class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // 4 Base cases
        if(target < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n != 0 && target == 0) return 0;
        if(n == 0 && target != 0) return 0;


        int ans=0; //represent no. of ways start loop from 1
        for(int i=1; i<=k; i++){
            ans = ans + numRollsToTarget(n-1, k, target-i);
            // n-1 bcz everytime we thorw dice the value of dice become decrease 
            //target-i bcz everytime when we are exploring faces we are subtracting the value from current target me se current face ki value minus kar rahe
        }
        return ans;


    }
};

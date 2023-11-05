class Solution {
public:
 bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer){

     //base case 
     if(ithCustomer == quantity.size()){
         return true;
     }

     for(int i=0; i<counts.size(); i++){

         if(counts[i] >= quantity[ithCustomer]){
             counts[i] -= quantity[ithCustomer];

    if(canDistributeHelper(counts, quantity, ithCustomer+1)){
        return true;
    }
    counts[i] += quantity[ithCustomer];
          
    }
    
         
        
     }
     return false;
 }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        //take count of nums array
        unordered_map<int,int>cntMap;
        for(auto num: nums){
            cntMap[num]++;
        }

        //pushing counts into it
        vector<int>counts;
        for(auto it: cntMap){
            counts.push_back(it.second); //yaha galti ki it nh it.second aaye ga
        }
        sort(quantity.rbegin(), quantity.rend());

        return canDistributeHelper(counts, quantity, 0);
    }
};

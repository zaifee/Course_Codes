class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
       //picking time
        int pickMatel  = 0;
        int pickPaper = 0;
        int pickGlass = 0;
        
       //last index 
       int lastM = 0;
       int lastP = 0;
       int lastG = 0;

       //travel time
        int travelM = 0;
        int travelP = 0;
        int travelG = 0;
     //Calculating garbage picking and travel time
        for(int i=0; i<garbage.size(); i++){
            string current = garbage[i];
            for(int j=0; j<current.length(); j++){
                char ch = current[j];

            if(ch == 'M'){
              pickMatel++;
              lastM  = i;
            }
            else if(ch == 'P'){
                pickPaper++;
                lastP = i;
            }
            else if(ch == 'G'){
                pickGlass++;
                lastG  = i;
            }
                }
            }


        //travel till last index calualated 
        for(int i=0; i<lastM; i++){
            travelM  += travel[i];
        }

        for(int i=0; i<lastP; i++){
           travelP += travel[i];
        }

        for(int i=0; i<lastG; i++){
            travelG += travel[i];
        }

        int ans = (pickMatel + travelM) + (pickPaper + travelP) + (pickGlass + travelG);

        return ans; 

        



    }
};

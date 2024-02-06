class compare{
public:
 bool operator()(pair<int,int>&a, pair<int,int>&b){
        int distA = a.first*a.first + a.second*a.second;
        int distB = b.first*b.first + b.second*b.second;

        return distA > distB;
   }

};

class Solution {
public:
  
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
// 
 priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;//min heap based on giving
// higher pq closer to origin. 
      for(auto P: points){
          pq.push({P[0], P[1]});
      }

      while(!pq.empty() && k--){
          auto& top = pq.top();

          ans.push_back({top.first, top.second});
          pq.pop();
      }
      return ans;

    }
};

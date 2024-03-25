class Solution {
public:
vector<int> topoSortBFS(int n, unordered_map<int, list<int> >& adjList){
        queue<int>q;
        unordered_map<int, int> Indegree;
        vector<int> topoSort;

//Initialized Indegree of all nodes
        for(auto i: adjList){
            for(auto nbr: i.second){
                Indegree[nbr]++;
            }
        }
// Push the all Indegree wali node into the queue
for(int node = 0; node < n; node++){
    if(Indegree[node] == 0){
        q.push(node);
    }
}

//ab bfs chalate hai 
while(!q.empty()){
    int frontNode = q.front();
    q.pop();
    topoSort.push_back(frontNode);

//if jo node pop hoi hai wo dubara rhi has as nbr then uski ek freq kam kar denge
    for(auto &nbr: adjList[frontNode]){
        Indegree[nbr]--;

        //check for zero 
        if(Indegree[nbr] == 0)
            q.push(nbr);
    }


}
    return topoSort;

}
    

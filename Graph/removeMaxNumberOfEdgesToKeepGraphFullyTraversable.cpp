class DSU{
private:

vector<int> parent;
vector<int> rank;
int components;

public:
//ctor 
DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1);
    components = n; //number of nodes in the graph

    //Initalizing the parent
    for(int i=0; i<n; i++){
        parent[i] = i; //initally every element acts as our parent;
    }

    
}



int find(int x){

    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y){


    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent) return;

//yaha gali kar rhe hai union me
    if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent; //yaha gali ki thi parent me update
    }
    else if(rank[x_parent] < rank[y_parent]){
        parent[x_parent] = y_parent; //yaha bhi same galti
    }else{
        //both rank are same so consider any parent and increase the rank by 1
        parent[x_parent] = y_parent; //yaha bhi galti ki thi
        y_parent += 1;
    }
        components--;

}

bool isSingleComponents(){
    return components == 1;
}

};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

    //Simulating the Story 

//Step1: first making two graph for Alice and Bob of n size
    DSU Alice(n);
    DSU Bob(n);

//step2: Sorting the edges in Descending order -- so that we can start with type3 edge first
    auto lambda = [&](vector<int>& v1, vector<int>& v2){
        return v1[0] > v2[0]; //it will sort in descending order
    };
    
    sort(begin(edges), end(edges), lambda);

//Step3: Traversing the graph and updating the rank of each node using union and find function

    int addingEdge = 0;
    for(auto &vec: edges){

        int type = vec[0]; //it will represent the type
        int u = vec[1];
        int v = vec[2];

        bool add = false;
        //Now Allocate the edge for type 3

        if(type == 3){

            if(Alice.find(u) != Alice.find(v)){
                Alice.Union(u, v);
                add = true;
            }
            if(Bob.find(u) != Bob.find(v)){
                Bob.Union(u, v);
                add = true;
            }

            if(add) addingEdge++;

    }else if(type == 2){ //bob turn

        if(Bob.find(u) != Bob.find(v)){
            Bob.Union(u, v);
            addingEdge++;
        }

    }else{
        //type 1 hai -- Alice can traverse the graph 
        if(Alice.find(u) != Alice.find(v)){
            Alice.Union(u, v);
            addingEdge++;
        }

    }
}

// cout << "Adding Edge " << addingEdge << endl;
// cout << "Edge Size " << edges.size() << endl;

    if(Alice.isSingleComponents() && Bob.isSingleComponents()){
        return edges.size() - addingEdge; 
    }

    return -1;


        
    }
};

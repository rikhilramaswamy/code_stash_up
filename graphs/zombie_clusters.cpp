/*
 * Complete the 'zombieCluster' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY zombies as parameter.
 */

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef unordered_set<int> mySet;

void buildGraph(vii &mygraph, vs &  zombies ){
    
    for(int i =0; i < zombies.size(); i++){
        string & temp = zombies[i];
        for(int j =0; j < temp.length(); j++){
            if(temp[j] == '1'){
                vi & tvec = mygraph[i];
                tvec[j] = 1;
            }
        }
        
    }
    
    
    
}

void dfs_explore(int curr, vii & mygraph, mySet &visited){
    //cout<<"\n bfs_explore trig for curr: :"<<curr;

    visited.insert(curr);
    
    vi & nbrs = mygraph[curr];
    for(int j =0; j < nbrs.size(); j++){
        // only if it is connected visit it 
        if( nbrs[j]== 1){
             auto itr = visited.find(j);
            if (itr == visited.end()){
                dfs_explore(j, mygraph, visited);
            }
        }
        
    }
     
}



int dfs_main(vii & mygraph, mySet &visited){
    int conn_comp_count =0;
    
    for(int i =0; i < mygraph.size(); i++){
        auto itr = visited.find(i);
        // if it is not visited
        if (itr == visited.end()){
           // cout<<"\n bfs_main trig for i :"<<i;
            ++conn_comp_count;
            dfs_explore(i, mygraph,visited );
        }
        
    }
    
    return conn_comp_count;
    
}

int zombieCluster(vector<string> zombies) {
    int num = zombies.size();
    vii mygraph(num, vi(num, 0));
    buildGraph(mygraph, zombies);
    mySet visited;
    
    /*cout<<"\n printing the adjacencny list....\n";
    for(int i=0; i < mygraph.size(); i++){
        vi temp = mygraph[i];
        for(auto elem : temp){
            cout<<"\t "<<elem;
        }
        cout<<"\n";
    }*/
    
   return dfs_main(mygraph, visited);
    //return -1;
}



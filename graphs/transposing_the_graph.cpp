typedef vector<int> vi;
typedef vector<vi > vii;

#define pb push_back

typedef unordered_map<int, vi> mygraph;
//typedef unordered_set<int> mySet;
typedef pair<int, vi> mygraph_pair;
/*
 * Complete the function below.
 */

void dfs_explore(mygraph & g1, Node *n ){
    if(n!= NULL ){
        int val = n->val;
        auto itr = g1.find(val);
        
        // if not visited
        if(itr == g1.end()){
            vi temp;
            for(auto e: n->neighbours){
                temp.pb(e->val);
            }
            
            g1.insert(mygraph_pair(val, temp));
            
            for(auto e: n->neighbours){
                auto itr1 = g1.find(e->val);
                if(itr1 == g1.end() ){
                   dfs_explore(g1, e); 
                }
                
            }
            
            
        }
        
    }
    
}


Node *build_other_graph(Node *node)
{
   mygraph g1;
   dfs_explore(g1, node);
   
    /*for(auto & elem: g1){
         int val = elem.first;
        vi & nbrs = elem.second;
        for(auto velem : nbrs ){ 
            cout<<"\t "<<velem;
        }  
        
    }*/
    
    
    int siz = g1.size();
    Node *ptr[siz+1];
    
     for(int i =1; i <=siz; i++){
        ptr[i] = NULL;
    }
    
    for(int i =1; i <= siz; i++){
        ptr[i] = new Node(i);
    }
    
    for(auto & elem : g1){
        int val = elem.first;
       // cout<<"\t val: "<<elem.first;

        vi & nbrs = elem.second;
        for(auto velem : nbrs ){ 
            //cout<<"\t nbrs: "<<velem;
            ((ptr[velem])->neighbours).pb(ptr[val]);
        }  
       // cout<<"\n";
    }

    if(siz ==0 )
        return NULL;
    
    return ptr[1] ;
    
}



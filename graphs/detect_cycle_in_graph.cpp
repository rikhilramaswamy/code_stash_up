typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<char> vc;
typedef unordered_map<int, vi> myMap;
typedef pair<int, vi> myMap_pair;
#define pb push_back

void buildGraph(myMap & m1, int N, int M, vii & edges){
    
    // Make sure you that you have an entry in your map for each vertex
    for(int i=0; i < N ; i++){
        vi temp;
        m1.insert(myMap_pair(i, temp));
    }
    
    
    for(int i=0; i < M ; i++){
        vi temp = edges[i];
        int x = temp[0];
        int y = temp[1];
        
        auto itr = m1.find(x);
        if(itr == m1.end()){
            vi buff;
            buff.pb(y);
            m1.insert(myMap_pair(x, buff));
            
        } else {
            (itr->second).pb(y);
            
        }
        
    }
    
    
    
}

bool DFS_explore(int vert, myMap & m1, vc & visit){
    // mark the node as discovered
    visit[vert] = 'd';
    
    auto itr = m1.find(vert);
    
    for( auto e : itr->second ){
        
        if(visit[e] == 'u'){
            if(DFS_explore(e, m1, visit))
                return true;
        } else {
            
            // Q: if vert is both discovered & processed=> cycle exists
            // I think only if vertex is discovered 
            if(visit[e] == 'd'){
                return true;
            }
        }
        
        
    }
    
    // we are done processing the node completely
    visit[vert] = 'p';
    return false;
}


/* char array for visited: undiscoverd, discovered, processed
    u: undiscoverd
    d: discovered
    p: processed
*/
bool DFS_main(myMap & m1){
    int sz = m1.size();
    
    vc visited(sz, 'u');
    
    for(auto & elem: m1){
        int vert = elem.first;
        assert(vert < sz);
        if(visited[vert] == 'u'){
            if(DFS_explore(vert, m1, visited))
                return true;
            
        }
    }
    
    // no cycle exists
    return false;
}

/*
 * Complete the 'hasCycle' function below.
 *
 * The function accepts INTEGER N, INTEGER M and 2D_INTEGER_ARRAY edges as parameter.
 * The function is expected to return a BOOLEAN.
 */

bool hasCycle(int N, int M, vector<vector<int>> edges) {
	// Write your code here
	
	myMap m1;
	
	buildGraph(m1, N, M, edges);
	
	/*for(auto elem : m1){
	    int x = elem.first;
	    cout<<"\n x: "<<x;
	    for(auto e: elem.second){
	        cout<<"\t "<<e;
	    }
	    
	}
	cout<<"\n done with graph printing\n";*/
	return DFS_main(m1);
	//return false;
	
}



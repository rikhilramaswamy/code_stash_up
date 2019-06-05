typedef vector<int> vi;
typedef vector< vi > vii;

typedef set<int> si;
#define pb push_back
class Solution {
public:
    /*int findCircleNum(vector<vector<int>>& M) {
        
    }*/
    
    
    void dfs_explore( vii & graph , si & visited, int i) {
	visited.insert(i);
	auto neighbors = graph[i];
	for( auto n : neighbors) {
		auto itr = visited.find(n);
		if(itr == visited.end()) {
			dfs_explore(graph, visited, n);
		}
	}
}

int dfs_main(vii & graph) {

	int num_comp = 0;
	si  visited;
	for( int i =0; i < graph.size(); i++) {
		auto itr = visited.find(i);
		if(itr == visited.end()){
			dfs_explore(graph, visited, i);
			++num_comp;
		}
	}

	return num_comp;
}



int findCircleNum(vector<vector<int>>& M) {
	int num_nodes = M.size();
	
    vii graph(num_nodes, vi(num_nodes, 0));
	
    // construct graph;
	for( int i = 0; i < num_nodes; i++){
		for(int j = 0; j < num_nodes; j++){
			if ( M[i][j] == 1) {
				(graph[i]).pb(j);
			}
		}
	}
	// do dfs
	
    return dfs_main(graph);
    //return 0;
}


};


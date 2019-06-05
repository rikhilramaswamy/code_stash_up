#include<climits>
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> npair;

typedef vector<npair> vpair;
#define pb push_back

vpair get_neighbors(int i, int j, int m , int n,vii & elevation_map){
    vpair temp;
    temp.pb(npair(-1,0)); // up neighbors
    temp.pb(npair(1,0));
    temp.pb(npair(0,-1));
    temp.pb(npair(0,1));
    
    vpair res;
    npair buff(-1, -1);
    int curr_min = INT_MAX;
    int curr = elevation_map[i][j];
    for( auto e : temp) {
        int x = i + e.first;
        int y = j + e.second;
        
        if(x >=0 && x < m && y >=0 && y < n) {
                int num = elevation_map[x][y];
                if(num < curr){
                    
                    if(num < curr_min) {
                        buff.first = x;
                        buff.second = y;
                        curr_min = num;
                    }
                }
        }
    }
    
    //assert(buff.first != -1);
    //assert(buff.second != -1);
    
    if(buff.first != -1 && buff.second != -1)
        res.pb(buff);
    
    return res;
}




void DFS_explore(int i, int j , vii & elevation_map, vii & visited, int m , int n, int & u_sink)
{
    visited[i] [j] = 0;
    
    vpair  temp = get_neighbors(i,j , m, n, elevation_map);
    
    // cell being sink (no neighbors)
    if(temp.empty()){
       // cout<<"\n one sink found\n";
        ++u_sink;
        visited[i] [j] = u_sink;
        return;
    }
    
    assert(temp.size() ==1);
    
    // cell being non-sink (one neighbor)
    for(auto elem: temp){
        // already visited mostly direct or indirect basin component
        // no need to recurse further
        if(visited[elem.first][elem.second] != -1)
        {
            visited[i] [j] = visited[elem.first][elem.second];
            return;
        } else {
            
            DFS_explore(elem.first, elem.second, elevation_map, visited, m, n, u_sink );
            assert(visited[elem.first][elem.second] != -1);
            visited[i] [j] = visited[elem.first][elem.second];
            return;
        }
    }
}

typedef map<int, int> nmap;
typedef pair<int,int> nmap_pair;

vi gather_result_array(vii & visited, int m, int n){
    nmap m1;
    for(int i =0 ;i < m ; i++){
        for(int j =0; j < m ; j++){
            auto itr = m1.find(visited[i][j]);
            // not found in map
            if(itr == m1.end()){
                m1.insert(nmap_pair(visited[i][j], 1));
            } else {
                (itr->second)++;
            }
            
            
        }
        
    }
    
    
    vi res;
    for(auto elem: m1){
        res.pb(elem.second);
        
    }
    
    sort(res.begin(), res.end());
    reverse(begin(res), end(res));
    
    return res;
    
}

/*
 * Complete the calculate_sizes_of_basins function below.
 */
vector<int> calculate_sizes_of_basins(vector<vector<int>> elevation_map) {
    /*
     * Write your code here.
     */
      int m = elevation_map.size();
      int n = elevation_map[0].size();
      //cout<<"\n m: "<<m<<"\t n: "<<n;
      
      vii visited (m, vi(n, -1));
      
     /* cout<<"\n visited elems are ....\n";
     for( int i =0 ; i < m ; i++){
          for(int j=0; j < n; j++){
              cout<<"\t "<<visited[i][j];
          }
        cout<<"\n";

     }
       cout<<"\n";*/
      
      int u_sink=0;
      for( int i =0 ; i < m ; i++){
          for(int j=0; j < n; j++){
              if(visited[i][j] == -1){
                  DFS_explore(i, j, elevation_map, visited, m , n, u_sink);
                  
              }
              
          }
          
      }
      
    /* cout<<"\n visited elems are ....\n";
     for( int i =0 ; i < m ; i++){
          for(int j=0; j < n; j++){
              cout<<"\t "<<visited[i][j];
          }
        cout<<"\n";

     }*/
      
      
    return gather_result_array(visited, m , n);
     
}



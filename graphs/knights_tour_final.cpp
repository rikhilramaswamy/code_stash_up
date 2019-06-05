#include <queue>
typedef pair<int,int> npair;
typedef vector<npair> npv;
typedef vector<int> vi;
typedef vector< vi> vii;
typedef unordered_set<npair> npset;
#define pb push_back
typedef queue<npair> myq;

npv get_neighbors(int crow, int ccol, int max_row, int max_col) {
    npv ref_list;
    ref_list.pb(npair(-2,-1));
    ref_list.pb(npair(-2, 1));
    ref_list.pb(npair(-1,-2));
    ref_list.pb(npair(1, -2));
    ref_list.pb(npair(-1, 2));
    ref_list.pb(npair(1, 2));
    ref_list.pb(npair(2, -1));
    ref_list.pb(npair(2, 1));
    
    npv res;
    
    for(auto cus_pair : ref_list) {
        int temp_row = cus_pair.first + crow ;
        int temp_col = cus_pair.second + ccol;
        if(temp_row >=0 && temp_row < max_row && temp_col >=0 && temp_col < max_col){
            res.pb(npair(temp_row, temp_col));
        }  
    }
    
    return res;
    
}

/*
 * Complete the function below.
 */
int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
    // Write your code here.
    vii grid(rows, vi(cols, -1)); // set all nodes to be unvisited
    myq q1;
    
    q1.push(npair(start_row, start_col));
    
  
    while(!q1.empty()){
        auto temp = q1.front();
        q1.pop();
        
        //cout<<"\n cell being inspected: temp.first: "<<temp.first<<"\t temp.second: "<<temp.second;
        //cout<<"\n cell_val: "<<cell_val;
        
        // useful for the first cell only
        // mark them visited
        if(grid[temp.first] [temp.second] == -1) 
           grid[temp.first] [temp.second] =0;
        
        // we found the target
        if(temp.first == end_row && temp.second == end_col)
            return grid[temp.first] [temp.second];
        
       npv nbrs =  get_neighbors(temp.first, temp.second, rows, cols);
        cout<<"\n neighbors of temp.first: "<<temp.first<<"\ttemp.second: "<<temp.second;
        for(auto cus_pair : nbrs) {
            cout<<"\n firs: "<<cus_pair.first<<"\t second: "<<cus_pair.second;
            
            
        }
        
        for(auto  t : nbrs){
            if( grid [t.first] [t.second] == -1){
                grid [t.first] [t.second] = grid[temp.first] [temp.second] +1;
                q1.push(t);
            }
 
        }
        
        
        
    }
    

    //cannot reach target     
    return -1;
    
}



typedef pair<int,int> mat_pair;
typedef queue<mat_pair> myq;
typedef map<mat_pair, int> myMap;
typedef pair<mat_pair,int> myMap_pair;


typedef vector<mat_pair> vp;
typedef vector<int> vi;
typedef vector<vi> vii;
#define pb push_back




vp get_neighbors(int r, int c, int max_r,int  max_c,vi dr, vi dc) {
    vp res;
    

    for(int i=0 ; i < dr.size(); i++){       
        int curr_r = r + dr[i];
        int curr_c = c + dc[i];
        
         if(curr_r >=max_r ||  curr_r< 0 || curr_c <0 || curr_c >= max_c )
             continue;
    
    
        mat_pair mp = mat_pair(curr_r, curr_c);
        res.pb(mp);
    }

    return res;   
}


int bfs(int r, int c, int max_r, int max_c, int tar_r, int tar_c,vii & mat,vi dr,vi  dc){
    
    if(r >= max_r || r < 0 || c <0 || c >= max_c )
        return -1;
        
     if(r == tar_r && c == tar_c){
         return 0;
    }

    
    mat[r] [c] =0;
    myq q1;
    q1.push(mat_pair(r,c));
    
    while(!q1.empty()){
        mat_pair pr = q1.front();
        cout<<"\n pr row: "<<pr.first<<"\t col: "<<pr.second;
        q1.pop();
        
        vp neighbor_list = get_neighbors(pr.first, pr.second, max_r,max_c,dr,dc);
        for(int i =0; i < neighbor_list.size(); i++){
            cout<<"\nTRIG1";
            mat_pair mp = neighbor_list[i];
            cout<<"new neighbor: r: "<<mp.first<<"\t col: "<<mp.second<<"\t val: "<<mat[mp.first] [mp.second];

            
            if(mp.first >= max_r || mp.first< 0 || mp.second <0 || mp.second >= max_c )
                continue;
            cout<<"\nTRIG3";

            if(mat[mp.first] [mp.second] == -1){
                            cout<<"\nTRIG2";

                
                mat[mp.first] [mp.second] = mat[pr.first][pr.second] + 1;
                cout<<"new neighbor: r: "<<mp.first<<"\t col: "<<mp.second<<"\t val: "<<mat[mp.first] [mp.second];
                
                if(mp.first == tar_r && mp.second == tar_c){
                    return mat[mp.first] [mp.second];
                }
                
                q1.push(mp);
                
                
            }
            
        }
        
        
        
        
    }
    

    return -1;
}





/*
 * Complete the function below.
 */
int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
    // Write your code here.
    
    vi dr;
    dr.pb(1);
    dr.pb(2);
    dr.pb(-1);
    dr.pb(-2);
    dr.pb(1);
    dr.pb(-1);
    dr.pb(-2);
    dr.pb(2);
    
    vi dc;
    dc.pb(2);
    dc.pb(1);
    dc.pb(-2);
    dc.pb(-1);
    dc.pb(-2);
    dc.pb(2);
    dc.pb(1);
    dc.pb(-1);
    
    // This is the visited array ;
    // initialised to -1(not visited)
    vii mat(rows, vi(cols, -1));
    /*
    for(int i=0; i < rows; i++){
        cout<<"\n print rows...";
        for(int j=0; j < cols; j++)
            cout<<"\t "<<mat[i][j];
        
    }*/
    
    return bfs(start_row,start_col,rows, cols, end_row, end_col,mat,dr, dc );

}



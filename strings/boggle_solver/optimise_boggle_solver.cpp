class ntrie;

typedef unordered_map<char, ntrie*> myMap;
typedef pair<char, ntrie*> myMap_pair;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector< vc > vcc;
typedef vector<int> vi;
typedef vector< vi> vii;
typedef pair<int, int> pairi;
typedef vector<pairi> vpair;
#define pb push_back
typedef unordered_set<string> ss;

class ntrie{
    public:
    
    myMap m1;
    bool is_end_of_word;
    
    ntrie(){
        
        is_end_of_word= false;
    }
    
    void insert_word(string wd){
        ntrie *t = this;
        for(auto e: wd){
            auto itr = t->m1.find(e);
            if(itr == t->m1.end()){
                ntrie *temp = new ntrie();
                t->m1.insert(myMap_pair(e, temp));
                t = temp;
            } else {
                t = itr->second;
            }
            
        }    
        t->is_end_of_word = true;
        
    }
    
    bool check_if_prefix_Exists(string wd){
        ntrie *t = this;

        for(auto e : wd){
             auto itr = t->m1.find(e);
             if(itr == t->m1.end()){
                 return false;
             } else {
                 t = itr->second;
             }  
        }
        return true;
    }
};




class Solution {
public:
    vpair get_neighbors(int r, int c, int num_rows, int num_cols, vpair & vps ){
        vpair res;
        for(auto p:  vps){
            int temp_r = r + p.first;
            int temp_c = c+ p.second;
            
            if(temp_r >=0 && temp_r< num_rows && temp_c >=0 && temp_c< num_cols ){
                res.pb(pairi(temp_r,temp_c ));    
            }
        }
        return res;
        
    }
    
    void DFS_explore(vii & local_visited, int i ,int j, int num_rows, int num_cols, vpair &vps, ntrie * t, vcc & board, vc & sofar, vs &res){
        
       // cout<<"\n DFS_expore invoked: i: "<<i<<"\tj: "<<j<<"\n";
        assert(t != NULL);
        local_visited[i][j] = 1;
        if(t->is_end_of_word){
            // add word in sofar to result 
            string temp;
            for(auto e: sofar){
                temp+= e;
            }
            
            res.pb(temp);   
        }
        
        vpair nbrs = get_neighbors(i, j,num_rows,  num_cols, vps );
        
        for( auto nbr1 : nbrs){
            int temp_r = nbr1.first;
            int temp_c = nbr1.second;
            auto itr = t->m1.find(board[temp_r][temp_c]);
            
            // if not visited and char in trie 
            if(local_visited [temp_r] [temp_c] == 0 && itr != t->m1.end()){
                sofar.pb(board[temp_r][temp_c]);
                DFS_explore(local_visited, temp_r, temp_c, num_rows,num_cols, vps, itr->second, board, sofar, res  );
                sofar.pop_back();   
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vs res;
        ntrie *t = new ntrie();
        //cout<<"\n board.size(): "<<board.size();
        //cout<<"\n board[0].size(): "<<board[0].size();
        int num_rows = board.size();
        int num_cols = board[0].size();
        
         // Add dictionary words to trie
         for( auto wd : words){
            //cout<<"\n inserting word: "<<wd;
            t->insert_word(wd);
        }
        
        vpair vps;
        vps.pb(pairi(-1,0));
        vps.pb(pairi(1,0));
        vps.pb(pairi(0,-1));
        vps.pb(pairi(0,1));
        
         //vii global_visited(num_rows , vi(num_cols, 0));
        
         // this is your DFS_MAIN
         for(int i =0 ; i < num_rows ; i++){
             for(int j =0; j < num_cols; j++){
                 //if(global_visited [i][j] ==0){
                     //string temp;
                     //temp+= board[i][j];
                     auto itr= t->m1.find(board[i][j]);
                     vc for_dfs;
                     if( itr != t->m1.end()) {
                            ntrie *st_trie = itr->second;
                            for_dfs.pb(board[i][j]);
                            vii local_visited(num_rows, vi(num_cols, 0));
                         assert(st_trie != NULL);
                            DFS_explore(local_visited, i, j, num_rows, num_cols, vps, st_trie, board, for_dfs,res );
                         
                   //  }
                     //global_visited [i][j] = 1;
                     
                 }
                 
             }
             
         }
        ss filter_dups;
        for(auto wd: res){
            filter_dups.insert(wd);
        }
        
        
        vs final;
        for(auto wd : filter_dups){
            final.pb(wd);
        }
        
        
       
        
       /* bool tres = t->check_if_prefix_Exists("oat");
        cout<<"\n oat tres: "<<tres;*/
        return final;
        
    }
};

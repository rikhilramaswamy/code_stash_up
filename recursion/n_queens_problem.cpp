
#define cont_tr(cont, it) \
 for(decltype(cont.begin()) it = cont.begin(); it != cont.end(); ++it)

#define pb push_back
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector < vs> vss;


bool all_rows_valid(vi & rows) {
        cont_tr(rows, it) {
                if((*it) == -1)
                        return false;
        }

        return true;
}

bool safe_to_place_queen(int row, int col, vb &cols_occupied, vb& slash_diag_occp, vb& backslash_diag_occup, int n) {
        if(cols_occupied[col])
                return false;

        if(slash_diag_occp[row+col])
                return false;

        if(backslash_diag_occup[ row - col + n -1])
                return false;

        return true;
}

bool nsolve(vss & final_res, vi &rows, vb &cols_occupied, vb& slash_diag_occp, vb& backslash_diag_occup, int curr_row, int n){

        // base case
        if(curr_row == n){
                if(all_rows_valid(rows)){
                       /* cout<<"\n printing resultt......";
                        int i =0;
                        cont_tr(rows, it) {
                                cout<<"\t i: "<<i<<"\t col: "<<(*it)<<"\n";
                        }*/
                    
                        vs temp1;
                        for(int i =0 ; i < n ; i++){
                            string sample;
                            int piv = rows[i];
                            for(int j=0; j < n ; j++){
                                if(j != piv) 
                                sample += '-'; 
                                else
                                    sample +='q'; 
                            }
                            sample += "\n";
                            temp1.pb(sample);
                        }
                         
                        final_res.pb(temp1);
                        return false;
                }

                return false;
        }


        for(int col=0; col < n; col++) {
                if(safe_to_place_queen(curr_row, col, cols_occupied, slash_diag_occp, backslash_diag_occup, n)){
                        //assert(rows[curr_row] != -1);
                        rows[curr_row] = col;
                        cols_occupied[col] = true;
                        slash_diag_occp[ curr_row + col] = true;
                        backslash_diag_occup[ curr_row - col + n -1]= true;

                        if(nsolve(final_res, rows, cols_occupied, slash_diag_occp, backslash_diag_occup, (curr_row +1), n))
                                return true;

                        rows[curr_row] = -1;
                        cols_occupied[col] = false;
                        slash_diag_occp[ curr_row + col] = false;
                        backslash_diag_occup[ curr_row - col + n -1]= false;

                }

        }

        return false;
    
}

vss find_all_arrangements(int n) {
    
    vss final_res;
    vi rows(n, -1);
    vb cols_occupied(n , false);
    vb slash_diag_occp(n + n -1, false);
    vb backslash_diag_occup(n + n -1, false);
    bool res = nsolve(final_res, rows, cols_occupied, slash_diag_occp, backslash_diag_occup, 0, n);
    
     cout << final_res.size() << " different arrangements possible." << endl << endl;
    //cout<<final_res.size()<<" different arrangements possible.";
    
    return final_res;
    
    
    
    
}




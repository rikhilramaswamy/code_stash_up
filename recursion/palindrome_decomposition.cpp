typedef vector<string> vs;
#define  pb push_back



bool nis_palin_helper(string &s, int low, int high ){
    if( (low > high) || low > high )
        return true;
    
    if(s[low] != s[high])
       return false;
    
    return nis_palin_helper(s, low+1, high-1);
    
}


bool nis_palin(string &s){
    
    return nis_palin_helper(s, 0, s.size()-1);
}






void generate_palindromic_decompositions_helper(vs &coll, string & orig, int pos, string so_far, int n ) {
    
    
    if(pos == n){
        coll.pb(so_far);
        return;
        
    }
    
    
    for(int i =1; i <= n-pos; i++){
        
        string temp = orig.substr(pos, i);
        if(nis_palin(temp)){
            string nn;
            if(so_far.empty())
                 nn =  temp ;
            else 
                 nn = so_far + '|' +  temp ;
            generate_palindromic_decompositions_helper(coll,orig, pos+i,nn, n );
        }
    }
    
}




/*
 * Complete the function below.
 */
vector <string> generate_palindromic_decompositions(string s) {
    
    vs vs_out;
   

    generate_palindromic_decompositions_helper(vs_out, s, 0, "",s.size());
    
    return vs_out;

}

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/*
 * Complete the function below.
 */
typedef vector<string> vs;
#define pb push_back

bool is_palin_helper(string & s){
     int low = 0;
     int high = s.length() -1;
     bool res = true;
     while(low < high && res){
         if(s[low] != s[high])
            res = false;
        ++low;
        --high;
     }
     return res;
 }
 
 void generate_palindromic_decomp_helper(string & orig, int index, string exp_sofar, vs & res){
     if( index == orig.length()){
         res.pb(exp_sofar);
         return;
     }
     
     for( int i = index; i < orig.length(); i++){
         // extract i chars from index 
         // check if that is palindrome 
         // if so : concat and solve for next valid index (i + length_chars)
         
         string temp = orig.substr(index, i -index+1);
         int len = i - index+1;
         if(is_palin_helper(temp)){
             if(index == 0){
                 generate_palindromic_decomp_helper(orig, index +len, exp_sofar +temp, res);
             } else {
                generate_palindromic_decomp_helper(orig, index +len, exp_sofar + "|" + temp, res);

             }
         }
     }
     
 }
 
vector <string> generate_palindromic_decompositions(string s) {
    vs res;
    string sofar ="";
    generate_palindromic_decomp_helper(s, 0,sofar, res );
    
    return res;
    

}


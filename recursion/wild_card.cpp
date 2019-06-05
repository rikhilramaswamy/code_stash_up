typedef vector<string> vs;
#define pb push_back
#define cont_tr(container, it) \
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)


void find_all_possibilities_helper(string &s, int pos,string sofar, vs & res){
    
    if(pos == s.length()){
        
        res.pb(sofar);
        return;
    }
    
    if(s[pos] == '?') {
        find_all_possibilities_helper(s, pos+1, sofar +'0', res);        
        find_all_possibilities_helper(s, pos+1, sofar +'1', res);
    } else {
        find_all_possibilities_helper(s, pos+1, sofar + s[pos], res);
        
    }
    
}

/*
 * Complete the find_all_possibilities function below.
 */
vector<string> find_all_possibilities(string s) {
    /*
     * Write your code here.
     */
    vs res;
        find_all_possibilities_helper(s, 0, "", res);
    
    
    cont_tr(res, it){
        cout<<"\t "<<(*it);
        
    }
    
    return res;
}



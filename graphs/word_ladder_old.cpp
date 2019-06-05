typedef vector<string> vs;
typedef queue<string> myq;
typedef map<string, string> msi;
typedef pair<string,string> pair_msi;
#define pb push_back


vs get_neighbors(string sample,msi & mymap, string start, string stop){
    
    vs res;
    for(int i =0;i < sample.length(); i++ ){
        int t = sample[i];
        
        for(int j = 'a'; j < ('z' +1) ; j++) {
            if(t != j){
                string suff =sample.substr(i+1);
                string pre = sample.substr(0, i);
                char temp = j;
                string ns = pre + string(1,temp) + suff;
                //cout<<"\nstring: "<<ns;
                
                decltype(mymap.begin()) it = mymap.find(ns);
                //if((it !=mymap.end()  && it->second  == "") || (ns == start) || (ns == stop) ) {
                if((it !=mymap.end()  && it->second  == "") || (ns == start) || (ns == stop) ) {

                    res.pb(ns);
                }
                
            }
            
        }
        
        
    }
    
    return res;
}


void  accumulate_path(string start,string  stop,vs & final,msi & mymap){
    string parent = stop;
    while(parent != start){
        final.pb(parent);
    decltype(mymap.begin()) it = mymap.find(parent);
         if(it == mymap.end() ){
               cout<<"exiting due to invalid parent";
         } else{
             parent= it->second;
         }
    }
    
    if(parent == start)
          final.pb(parent);  
    
    
}




/*
 * Complete the function below.
 */
vector<string> string_transformation(vector<string> words, string start, string stop) {
    msi mymap;
    vs final;
    for(int i =0; i < words.size(); ++i) {
        mymap.insert(pair_msi(words[i], ""));
    }
    
    /*decltype(mymap.begin()) it_start = mymap.find(start);
    decltype(mymap.begin()) it_end = mymap.find(stop);
    
    if(it_start == mymap.end() ||  it_end == mymap.end() ){
        cout<<"\n entered invalid input block";
        final.pb("-1");
        return final;   
    }*/
    /*
     decltype(mymap.begin()) it_end = mymap.find(stop);

    if(it_end == mymap.end() ){
        mymap.insert(pair_msi(stop, ""));
    }
    
    decltype(mymap.begin()) it_start = mymap.find(start);
     if(it_start == mymap.end() ){
        mymap.insert(pair_msi(start, "NONE"));
    }*/
    
    myq q1;

    
    q1.push(start);
    
    
    while(!q1.empty()) {
        string curr = q1.front();
        //cout<<"\n TRIG1: str is : "<<curr;

        q1.pop();
        
        if(curr == stop) {
            //print the parents using stack
            accumulate_path( start, stop, final,mymap);
             vs vs1(final.rbegin(), final.rend());
            return vs1;
           // return final;
        }
        
        decltype(mymap.begin()) it = mymap.find(curr);
        
        // MArk current as visited
        //it->second = 0;
        vs res = get_neighbors(curr, mymap, start, stop);
        /*// seems like this is NOT leading us to the destination 
        // so remove this parent from result vector
        cout<<"\n neighbors of curr: "<<curr<<"are : "<<res.size();
        if(res.empty() && !final.empty()){
            cout<<"POPPING....STR:"<<final[final.size()-1];
            final.pop_back();
        }*/
        
        for(int i =0 ; i < res.size(); i++) {
            string curr_str = res[i];
            decltype(mymap.begin()) it = mymap.find(curr_str);
            // add neighbor to queue if it is not visited 
            if(it->second == ""){
                it->second = curr;
                q1.push(curr_str);
                
            }
            
            
            
        }
    }
    
    /*
    
    for(int i =0 ; i < final.size(); i++)
        cout<<"\t string: "<<final[i]; */
    
    vs neg_final;
    neg_final.pb("-1");
    return neg_final;
}



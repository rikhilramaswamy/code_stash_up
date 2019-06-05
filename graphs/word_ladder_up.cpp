#include<unordered_map>
#include<queue>

typedef unordered_set<string> mywords;
typedef vector<string> vs;
typedef unordered_map<string, string> mymap;
typedef pair<string, string> mymap_pair;
typedef queue<string> myq;

#define pb push_back

vs get_valid_neigbors(string curr, mywords & dictionary ){
    vs res;
    for(int i=0; i < curr.length(); i++){
        for(int j = 'a'; j <= 'z'; j++){
            string temp = curr.substr(0, i);
            temp += j ;
            temp += curr.substr(i+1);
            if( temp != curr ){
                auto itr = dictionary.find(temp);
                if(itr != dictionary.end()){
                    res.pb(temp);
                }
            }
            
        }
    }
    
    return res;
}


//get_valid_neighbors()
    
vs get_final_list(mymap & prevs, string end, string start){
    vs res;
    string temp = end;
    res.pb(end);
      while(temp != "" && temp != start){
        auto itr = prevs.find(temp);
        if(itr != prevs.end()){
            string here = itr->second;
            res.pb(here);
            temp = here;
        } else {
            temp = "";
        }
    }
    
    vs res2 (res.rbegin(), res.rend());
    
    return res2;
}


vs nbfs (string start, string end, mymap & prevs, mywords & dictionary ){
    vs res;
    myq m1;
    mywords visited;
    //visited.insert(start);
    m1.push(start);
    // this bool is used to allow start and stop to be the same 
    bool first = true;
    
    while(!m1.empty()) {
        string temp = m1.front();
        m1.pop();
        
        if(temp == end && !first){
            cout<<"\n trig this block";
           res=  get_final_list(prevs, end, start);
            if(res.size() > 1)
                return res; 
            else 
                goto end;
        }
        
        first = false;
        vs nbrs = get_valid_neigbors(temp, dictionary );
       
        /* cout<<"\n valid neighbors of temp: "<<temp<<"\t are ...\n";
        for(auto e : nbrs){
            cout<<"\t "<<e;
        }
        cout<<"\n";*/
        
        for( auto n : nbrs){
            auto itr = visited.find(n);
            if(itr == visited.end()) {
                prevs.insert(mymap_pair(n, temp));
                m1.push(n);
            }
        }

    }
   
    end:
    // if we are here seems like there is NO path from start to end 
    vs final;
        final.pb("-1");
    return final;
}



/*
 * Complete the function below.
 */
vector<string> string_transformation(vector<string> words, string start, string stop) {
    
    mywords dictionary;
    mymap prevs;
    
    // add words to a set for faster look up 
    for(auto wrd : words){
        dictionary.insert(wrd);
    }
   // dictionary.insert(start);
    dictionary.insert(stop);

    return nbfs(start, stop,prevs, dictionary);
}



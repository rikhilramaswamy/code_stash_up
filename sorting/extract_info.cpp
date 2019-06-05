/*
#include <map>
typedef vector<string> vs;
typedef pair<string, int> cp;
typedef map<string, cp> mymap;
typedef pair<string, cp> mymap_pair;
#define pb push_back

#define cont_tr(container, it)\
    for( decltype(container.begin()) it = container.begin(); it != container.end(); ++it)



 
vector<string> solve(vector<string> arr) {
    
    mymap mymap1;
    
    cont_tr(arr, it){
        
        string sample = (*it);
        string::size_type pos = sample.find(' ');
        string key ="" ;
        string val = "";
        if(pos != string::npos){
                key = sample.substr(0, pos);
                val = sample.substr(pos+1);
            
        decltype(mymap1.begin()) mymap_it = mymap1.find(key);
            if(mymap_it != mymap1.end()){
                cp & temp = mymap_it->second;
                temp.second++;
                string curr = temp.first;
                
                if(val.compare(curr) > 0)
                    temp.first = val;
                
            } else {
                cp cp1(val, 1);
                mymap_pair p1(key, cp1);
                mymap1.insert(p1);
  
            }
        }  
    }
    
    
    
    vs res;
    
    decltype(mymap1.begin()) mymap_it = mymap1.begin();
    while(mymap_it != mymap1.end()){
        string s = mymap_it->first;
        s+= ":" + to_string(mymap_it->second.second) + "," + mymap_it->second.first;
        cout<<"\nstring s:"<<s;
        res.pb(s);
        mymap_it++;
        
    }
    
    return res;
    

}*/


#include <unordered_map>
typedef pair<string, string> ss;
typedef pair<int, string> mypair;

typedef unordered_map<string, mypair> mymap;
typedef pair<string, mypair> mymap_ds;

typedef vector<string> vs;

#define pb push_back

ss splitstr(const string &s){
    int n = s.find(' ');
    string first1 = s.substr(0, n);
    string second2 = s.substr(n);
    return ss(first1, second2);
}

vs get_info(mymap & m1){
    vs res;
    
    for(auto const & elem : m1){
        string temp = elem.first + ":" + to_string(elem.second.first) +"," + elem.second.second;
        res.pb(temp);
    }
    
    return res;
}

vector<string> solve(vector<string> arr) {
    mymap map1;
    
    for(auto const & str : arr) {
        auto inp_pair = splitstr(str);
        auto itr = map1.find(inp_pair.first);
        // input string is NOT in hashtable
        if(itr == map1.end()){
            map1.insert(mymap_ds(inp_pair.first, mypair(1, inp_pair.second)));
            
            
        } else {
            auto & temp = (*itr);
            string s = temp.second.second;
            if(s.compare(inp_pair.second) < 0 ) {
                temp.second.second = inp_pair.second;
                ++(temp.second.first);
                
            }
            
        }
    }
    
    return get_info(map1);
}

    


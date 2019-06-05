typedef vector<int> vi;
typedef vector< vi> vii;
typedef vector<string> vs;
//typedef set<string> vs;

#define pb push_back
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)


//Complete the function below.
 
typedef vector<bool> vb;
typedef vector<string> vs;
#include<unordered_set>




void gather_strings(int index, vb & db_table, vs &res, string sofar, string &orig){
    //cout<<"\nindex is:"<<index;
    if(index == db_table.size() -1){
        //cout<<"\n sofar:"<<sofar;
            res.pb(sofar);
        return;
    }
    
    for(int i = index+1; i< db_table.size(); i++){
        if(db_table[i]){
            //cout<<"\n i true being:"<<i<<"\t index: "<<index;
            //int len = index - i -1;
            int len = i - index;

            string temp = orig.substr(index, len);
           // cout<<"\n temp is:"<<temp;
            if(temp != orig)
                gather_strings(i, db_table, res, sofar  + temp + " " ,orig );
            
        }
        
    }
 
}


vector < string > wordBreak(string strWord, vector < string > strDict) {
    vs res;
    vb dp_table(strWord.size()+1, false);
    unordered_set<string> us;
    
    for(auto elem: strDict){
        us.insert(elem);
    }
    
    for(int j= strWord.size(); j>=0; j--){
        if(j == strWord.size()){
            dp_table[j] = true;
            continue;
        }
       // cout<<"\nj is:"<<j;
        for(int k=0; k <=j ; k++){
            int diff = j - k +1;
            cout<<"\nk: "<<k;
            string temp = strWord.substr(k, diff);
           // cout<<"\t temp: "<<temp;
            
            //auto itr = find(strDict.begin(), strDict.end(), temp);
            auto itr = us.find( temp);
            if(itr != us.end()) {
                cout<<"\n TRIG: temp was foudn: "<<temp<<"\t diff was:"<<diff;
                if(k ==0 && dp_table[k] )
                    continue;
                dp_table[k] = dp_table[k+diff];
            } 
        }
    }
    
    cout<<"\n final:"<< dp_table[0];
    
    cout<<"\n printing the bool table....";
    for(auto e : dp_table)
        cout<<"\t "<<e;
    
    if(dp_table[0])
     gather_strings(0, dp_table, res, "", strWord);
    
    
   return res;
}



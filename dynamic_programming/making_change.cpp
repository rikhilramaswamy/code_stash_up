typedef vector<int> vi;
typedef vector<vi > vii;
#define pb push_back

#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)

int makeChange_helper(int target, vi intDenominations, vi v1, vii &res){
    if(target == 0){
        res.pb(v1);
       // cout<<"res :"<<res;
         return 0;
    }
    
    int min = 32767;
    
    for(int i=0; i < intDenominations.size(); ++i ){
        int temp = 32767;
        vi interim(v1.begin(), v1.end());
        if(target >= intDenominations[i]){
            interim.pb(intDenominations[i]);
            temp = 1+ makeChange_helper(target-intDenominations[i], intDenominations, interim, res) ;
            if( temp < min){
                min = temp;
            }
        }   
    }
    
    /*res += ",";
    res += to_string(res_denom);*/
    //cout<<"\n final_res: "<<final_res;
     //res+= to_string(res_denom);
    return min;
}


/*
 * Complete the function below.
 */
void makeChange(int C, vector < int > intDenominations) {
   vii res;
    vi temp;
    int min = makeChange_helper(C,intDenominations,temp, res );
    
    int min_size = 32767;
    int index =32767;
    for(int i =0 ; i < res.size(); ++i){
        int size = res[i].size();
        if(size < min_size ){
            cout<<"\ntrig....";
            min_size = size;
            index = i;
            
        }
        
    }
    
    vi final = res[index];
    string ss;
    cont_tr(final, it){
        ss += to_string(*it) + ", "; 
        
    }
    
    cout<<"\n min is: "<<min;
    cout<<"\n ss: "<<ss;
    //cout<<"\n"<<res;

}



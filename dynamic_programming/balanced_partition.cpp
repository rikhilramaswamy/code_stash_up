typedef vector<bool> vi;
typedef vector<vi> vii;
typedef vector<int> vint;
typedef vector<vint> viint;

// Complete the balanced_partition function below.
vector<vector<int>> balanced_partition(vector<int> arr) {
    
    int sum=0;
    for( auto const & elem : arr){
        sum += elem;  
    }
    
    int target = sum/2;
    cout<<"\n target:"<<target;
    int m = arr.size();
        cout<<"\nm :"<<m;

    
    vii dp_table(m+1, vi(target+1, false) );
    
    for(int i = m ; i >=0; i--){
        for(int t = 0 ; t <= target; t++){
            if(t ==0){
                dp_table [i][t] = true;
                continue;
            }
            
            if(i == m){
                dp_table[i] [t] = false;
                continue;
            }
            
            if( arr[i] <= t) {
                dp_table[i] [t]  = dp_table[i +1] [(t - arr[i]) ] || dp_table[i+1] [t] ;
                
            } else{
                dp_table[i] [t] = dp_table[i+1] [t] ;
            }
        }
    }    
    

  cout<<"\n res: " <<dp_table[0] [target]<<"....\n" ;
    
for(int i=0; i <=m; i++ )    {
    for(int j =0; j <=target; j++) {
        cout<<"\t "<<dp_table[i] [j]; 
    }
 cout<<"\n";   
}
    
    viint res;
    return res;
    
}



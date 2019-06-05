typedef vector<int> vi;

/*int maxStolenValue_helper(int i, vi & arrHouseValues){
    int arr_size = arrHouseValues.size();
    
    if( i == arr_size )
        return 0;
    
    // including index i 
    int max = arrHouseValues[i];
    if( (i+2) < arr_size) {
        for(int j =2; i+j < arr_size; j++){
            int res = arrHouseValues[i] +maxStolenValue_helper(i+j, arrHouseValues);
            if(res > max){
                max= res;
            }
 
        }
 
    }
    
    int max_ex = 0;
    // excluding index i
    
    max_ex = maxStolenValue_helper(i+1, arrHouseValues);
    if(max_ex > max){
        max= max_ex;
    }
    
    return max;
 




// Complete the function below.

int maxStolenValue(vector < int > arrHouseValues) {

    return maxStolenValue_helper(0,arrHouseValues );
}*/


int maxStolenValue(vector < int > arrHouseValues) {
 
    if(arrHouseValues.empty()) return 0;
    
    vi dp_table(arrHouseValues.size() +1, 0);
    
    
    //prepopulate the base-value
    dp_table[dp_table.size() - 1] = 0;
    
    for(int i = dp_table.size() - 2; i >=0; i--){
        int pick_case =arrHouseValues [i];
        if(i+2 < dp_table.size())
            pick_case +=  dp_table[i+2];
        
        int no_pick_case =0;
        if(i+1 < dp_table.size())
            no_pick_case += dp_table[i+1];
            
        dp_table[i] = max(pick_case, no_pick_case );
        //dp_table[i] = max(arrHouseValues[i] + dp_table[i+2], dp_table[i+1] );
    }
    
    return dp_table[0];
}



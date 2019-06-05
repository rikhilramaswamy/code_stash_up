typedef vector<int> vi;
typedef vector<vi> vii;


// Complete the maxWin function below.
int maxWin(vector<int> v) {
    int n = v.size();
    
    vii dp_table(n, vi (n , 0));
    
    for(int i= n-1; i>=0; i --) {
        for(int j=i ; j <n; j++){
            if(i == j) {
               dp_table[i][j] = v[i]; 
                continue;
            } else if(i >j ){
                dp_table[i][j]= 0;
                continue;
                
        // this is just an optimised base case;
        // code will work without this as well
            } else if (i +1 == j){
                dp_table[i][j] = max(v[i], v[j]);
            } else {
                
                if(i < n && i>=0 && j < n && j>=0){
                    
                    int temp1 = min((v[i] + dp_table[i+2][j]), v[i]+dp_table[i+1][j-1]);
                    int temp2 = min((v[j] + dp_table[i][j-2]), v[j] + dp_table[i+1][j-1]);
                    
                    dp_table[i][j] = max(temp1, temp2);
                    
                    
                } else {
                    int temp1 = v[i];
                    int temp2 = v[j];
                    dp_table[i][j] = max(temp1, temp2);
                    
                    
                }
                
                
            }
            
            
        }
        
    }
    
    return dp_table[0][n-1];
    


}



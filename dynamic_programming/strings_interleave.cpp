/*
 * Complete the 'doStringsInterleave' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 *  3. STRING i
 */
typedef vector<bool> vi;
typedef vector<vi> vii;


bool doStringsInterleave(string a, string b, string i) {
    int M = a.length();
    int N = b.length();
    int K = i.length();
    
    vii dp_table(M+1, vi(N+1, false ));
    
    for(int g = M; g >=0; g--){
        
        for(int j = N; j >=0; j--){
            if(g + j == K) {
               dp_table[g][j] = true; 
                continue;
            }
            
            if(a[g] == i[g+j] && b[j] ==  i[g+j]){
                dp_table[g][j] = dp_table[g+1][j] || dp_table[g][j+1];
            } else if( a[g] == i[g+j]){
                dp_table[g][j] = dp_table[g+1][j];
            } else if(b[j] == i[g+j]){
                dp_table[g][j] = dp_table[g][j+1];
            } else 
                dp_table[g][j] = false;
            
        }
        
    }
    
    return dp_table[0] [0];

}



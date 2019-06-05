/*
int levenshteinDistance_helper(int i, int j, string strWord1, string strWord2, int src_size, int dest_size ){
   cout<<"\nlevenshteinDistance_helper with i: "<<i<<"\t j: "<<j;
    
     if( j >= dest_size &&  i>= src_size)
        return 0;
    
    if( j == dest_size && i == src_size)
        return 0;
    //TODO: is there a possiblity that we need to take care of j >dest_size , i >src_size
    
    if(j == dest_size){
        cout<<"\n TRIG..";
        return src_size - i;
        
    }
    
    if(i == src_size){
        return dest_size - j;
    }
    
    if(strWord1[i] == strWord2[j])
        return levenshteinDistance_helper(i+1, j+1, strWord1, strWord2,src_size,  dest_size );
    
    int min = 32789;
    // replace operation
    int res = 1+  levenshteinDistance_helper(i+1, j+1,strWord1, strWord2,src_size,  dest_size );
    if(res < min)
        min = res;
    
    // insert operation
    res = 1+ levenshteinDistance_helper(i, j+1, strWord1,  strWord2, src_size, dest_size);
    if(res < min)
        min = res;
    
    // delete operation
    res = 1+ levenshteinDistance_helper(i+1, j, strWord1, strWord2, src_size, dest_size);
    if(res < min)
        min = res;
    
    return min;
    
}


int levenshteinDistance(string strWord1, string strWord2) {
    
    int src_size = strWord1.size();
    int dest_size = strWord2.size();
    cout<<"\n src_size: "<<src_size<<"\t dest_size: "<<dest_size;
    return levenshteinDistance_helper(0, 0, strWord1, strWord2,src_size, dest_size  );
    


}
*/

typedef vector<int> vi;
typedef vector<vi> vii;

int levenshteinDistance(string strWord1, string strWord2) {
    int m_size = strWord1.length() +1;
    int n_size = strWord2.length() +1;
    vii ntable(m_size, vi(n_size, 0));
    
    int m = strWord1.length();
    int n = strWord2.length();
    
    // prepopulate the table
    int k = strWord1.length();
    for(int j =0; j <= n ; j++)
        ntable[k][j] = n - j;
    
    // prepopulate the table
    int l = strWord2.length();
    for(int i =0; i <= m ; i++)
        ntable[i][l] = m - i;
    
    
    
    for(int i = m-1; i >= 0; --i){
        for(int j= n-1; j>= 0; --j){
            if(strWord1[i] == strWord2[j]) {
                ntable[i] [j] = ntable[i+1] [j+1];
            }    else {
                ntable[i] [j] = min (min(ntable[i] [j+1], ntable[i+1] [j]), ntable[i+1][j+1]) +1 ;
            }

        }
    }
    
    return ntable[0][0];
}

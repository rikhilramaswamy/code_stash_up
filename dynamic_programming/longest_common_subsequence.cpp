typedef vector<int> vi;
typedef vector< vi> vii;

int lcs_helper(vii & dp_table, int M , int N,string strX, string strY ){
    
    for(int i = M ; i >=0; i-- ){
        for(int j = N; j >=0 ; j--){
            if( i == M || j == N){
                dp_table[i] [j] = 0;
                continue;
            }
            
            if(strX[i] == strY[j]){
                dp_table[i] [j] = 1 + dp_table[i+1] [j+1];
            } else {
                
                dp_table[i] [j] = max(dp_table[i] [j+1], dp_table[i+1] [j]);
            }
            
        }
 
    }
    return dp_table[0] [0];
}


string lcs_string_helper(vii & dp_table, string s1, string s2){
    int i =0; int j =0;
    int M = s1.length();
    int N = s2.length();
    string res = "";
    while(i < M && j < N) {
        if(s1[i] == s2[j]){
            res += s1[i];
            ++i;
            ++j;
        } else {
            int temp = dp_table[i] [j];
            if(dp_table[i+1][j] == temp){
                ++i;
            } else if(dp_table[i][j+1] == temp){
                ++j;
            }
            
            
        }
 
    }
    
    return res;
}


// Complete the getLCS function below.
string getLCS(string strX, string strY) {
    int M = strX.length();
    int N = strY.length();
    
    vii dp_table(M+1, vi(N+1, 0));
   int max_len_string =  lcs_helper(dp_table, strX.length(),strY.length(), strX, strY );
    //cout<<"\n  max_len_string: "<<max_len_string;
    
    return lcs_string_helper(dp_table,strX, strY );
    
}



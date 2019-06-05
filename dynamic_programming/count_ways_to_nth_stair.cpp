typedef vector<int> vi;

/*int countWaysToClimb_helper(vi & steps, int n){
    if (n == 0){
        return 1;
    }
   
    int res =0;
    for(int i =0 ; i < steps.size(); i++){
        if( n >= steps[i]){
           res +=  countWaysToClimb_helper(steps, n - steps[i]);
        }
         
    }

    return res;  
}



 // Complete the countWaysToClimb function below.
int countWaysToClimb(vector<int> steps, int n) {
   
        
   return countWaysToClimb_helper(steps, n);
    
}*/

int countWaysToClimb(vector<int> steps, int n) {
    vi ntable(n+1, 0);

    //prepopulate the base condition
    ntable[0] = 1;
    //cout<<"\ni: "<<0<<"\tntable[i]: "<<ntable[0];
    
    for(int i=1; i < (n+1); i++ ){
        int sum = 0;
        for(int j =0; j < steps.size(); j++){
            if( steps[j] <= i ) {
                //cout<<"\n trig for i: "<<i<<"\tsteps[j]: "<<steps[j];
                sum += ntable[(i-steps[j])] ;   // this is ???
                //cout<<"\n sum: "<<sum;
            }
        }
        
        
        ntable[i] = sum;
        //cout<<"\ni: "<<i<<"\tntable[i]: "<<ntable[i];
    }
    
    return ntable[n];
}





typedef vector<int> vi;
typedef queue < int> myQueue;

// Both moves & visited start from zero-index to n-1 zero-index
// caveeat: value of moves is indexed from 1 (so make sure to decrement 1 before consuming to adjust)

// Complete the minNumberOfRolls function below.
int minNumberOfRolls(int n, vector<int> moves) {
    //cout<<"\n starting the program";
    vi visited(n, -1);
    myQueue q1;
    q1.push(0);
    // mark start as visited
    visited[0] = 0;
    
    /*cout<<"\n printing the MOVES array";
            for(auto elem: moves){
                cout<<"\t "<<elem;
            }
            
     cout<<"\n done with MOVES array";*/

    
    while(!q1.empty()) {
        //cout<<"\n entered while ";
        
        int curr = q1.front();
        q1.pop();
        if(curr == n-1){
           /* cout<<"\n printing the visited array";
            for(auto elem: visited){
                cout<<"\t "<<elem;
            }
            
            cout<<"\nresult is: "<<visited[curr];*/
            return visited[curr];
        }
        
        // get valid neighbors and push to queue 
        for(int i = curr +1 ; i <=(curr +6)  && i < n; i++){
            // if cell is not visited
            if(visited[i] == -1) {
                if(moves[i] == -1) {
                    // this is NO snake NOT ladder
                    q1.push(i);
                    visited[i]  = visited[curr] +1;

                } else {
                    // snake or ladder
                    int temp = moves[i] -1;
                    if(temp >= 0 && temp <n && visited[temp] == -1) {
                         q1.push(temp);
                         visited[temp] =  visited[curr] +1;
                         // Q) do we have to set visited?
                        visited[i]  = visited[curr] +1;
                        
                    } else{
                        // dest you are coming up is already visited 
                        // so do NOT add on queue just mark visited
                        visited[i]  = visited[curr] +1;
                    }
                   
                } 
                
                
            }
            
        }
        
        
        
    }
    
    /*cout<<"\n printing the visited array at the end";
            for(auto elem: visited){
                cout<<"\t "<<elem;
            }
            cout<<"\n\n done printing\n";*/
    return -1;
    
}



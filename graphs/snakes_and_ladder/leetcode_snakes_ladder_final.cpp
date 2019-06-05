typedef vector<int> vi; 
typedef queue<int> mq;

class Solution {
public:
    int bfs_helper(vi & nb, vi & visited, int m , int n){
        int dest = m *n;

        mq q1;
        q1.push(1);
        visited[1] = 0;
        
        while(!q1.empty()){
            int res = q1.front();
            q1.pop();
            if( res == dest){
                return visited[res];
            }
            
            // neighbors 
            for(int i =1; i <=6 ; i++){
                int temp = res +i;
                if ( temp > 0 && temp<= dest){
                    int buff;
                    / NO snake NO ladder
                    if( nb[temp] == -1){
                        buff = temp;
                    }else {
                        // eITHER snake or ladder
                        buff = nb[temp];
                    }
                    
                    if(visited[buff] == -1){
                        visited[buff] = visited[res] +1;
                        q1.push(buff);
                    }
                }
                
                
            }
        }
        return -1;      
    }
      
    int snakesAndLadders(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vi nb(m*n +1, -1);
        vi visited(m*n +1, -1);
    
        // this does NOT work
        /*for(int i =0; i < m; i++){
            for(int j=0; j < n; j++){
                if(board [i] [j] != -1){
                    nb[(i*m) + j +1]= board [i] [j];  
                }
            } 
        }*/
        
        
        // Notice the order of the board ;
        // first row of matrix is ACTUALLY last row of the board
        // hence this code
        int count =1;
        bool flag = true;
         for(int i =m-1; i >= 0; i--){
             
             if(flag){
                for(int j=0; j < n; j++){
                    if(board [i] [j] != -1){
                        nb[count]= board [i] [j];  
                    }
                    count++;
                } 
                flag = false;
             } else {
                for(int j = n-1; j >=0; j--){
                    if(board [i] [j] != -1){
                        nb[count]= board [i] [j];  
                    }
                    count++;
                }
                flag = true;
             }
        }
        
        
       /* for(int i =1 ;i < nb.size(); i++){
            cout<<"\n i "<<i<<"\t arr[i]:"<<nb[i];
        }*/ 
        
        return bfs_helper(nb, visited,m , n);  
    }
};

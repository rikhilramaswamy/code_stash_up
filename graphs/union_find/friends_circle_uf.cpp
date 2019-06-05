typedef vector<int> vi;

#define pb push_back
class Solution {
public:
    int find_parent(int i, vi &parent ){
        if( parent[i] == -1 )
            return i;
      return   find_parent(parent[i], parent);
     
    }
    bool nunion(int i , int j , vi &parent){
        int p_i = find_parent(i, parent);
        int p_j = find_parent(j, parent);
        
        // they have SAME common parent
        // 1) NO need to unionise
        // 2) Already unionised
        if(p_i == p_j)
            return false;
        
        parent[p_i] = p_j;
        return true;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty())
            return 0;
        
        int m = M.size();
        int n = M[0].size();
        if( m ==0 || n == 0)
            return 0;
        
        // make sure that it is a square matrix
        assert(m == n);
        vi parent(m, -1);
        
        // you have made sure that they have common parent 
        for(int i =0; i < m ; i++){
            for(int j =0 ; j < m ; j++){
                if( i !=j && M[i][j] == 1 )
                    nunion(i, j, parent);
                
            }
        }
        
        
        // return the # of  elements with parent:-1 
        int res =0;
        for(auto & e: parent ){
            if(e == -1) ++res;

        }
        
        
        return res;
    }
};

typedef vector<int> vi;
#include <algorithm>

class Solution {
public:
    int trap_helper(vi & arr){
        vi left_max( arr.size(), -1);
        vi right_max ( arr.size(), -1);
        
        // pass1: compute the left max of each index ; 
        // note: lmax is exclusive of current index
        int lmax = arr[0];
        for(int i =1; i < arr.size(); i++){
            left_max[i] =lmax;
            lmax = max(lmax,arr[i] );
        }
        
        // pass2: compute right max
        int rmax = arr[arr.size()-1];
        for(int i = arr.size()-2; i >=0 ; i--){
            right_max[i] = rmax;
            rmax = max(rmax,arr[i] );
        }
        
        int total_vol = 0;
        for(int i=0; i < arr.size(); i++){
            if(left_max [i] == -1 || right_max[i] == -1)
                continue;
            int temp = min(left_max[i],right_max[i] );
            int pos_res= temp - arr[i];
            if( pos_res > 0 )
                total_vol += pos_res;
        }
    
        return total_vol;
          
    }
    
    
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        
        return trap_helper(height);
        
    }
};

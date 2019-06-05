typedef vector<int> vi;
#include <climits>

using namespace std;

class Solution {
public:
    
    int findMin_helper(vi & a){
        int low = 0;
        int high = a.size()-1;
       
	/* assumption: array being passed beyond this point is 
	/ an ascending sorted rotated array */
	 
        while(low < high ){
            int mid = (low + high)/2;
            if( a[mid] > a[high]){
                low = mid+1;
            } else if (a[mid] < a[high]){
                high = mid ;
            } else {
                --high;
            }
            
        }
        
        return a[low];
    }
    
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        if(nums.size() ==1 )
            return nums[0];
        
        return findMin_helper(nums);
        
        
    }
};

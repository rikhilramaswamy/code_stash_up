typedef vector<int> vi;
#include<climits>

class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        if(heights.empty())
            return max_area;
        
        // pass1: find the left_min at every index INCLUSIVE of curr_index 
        // NOTE: HERE we want the contiguous min 
        // Unlike trapping rain water problem
        vi left_min(heights.size(), -1);
        for(int i = 1; i < heights.size(); i++ ){
            int p = i-1;
            while( p >=0 && heights[p] >= heights[i]){
                p = left_min[p];
            }
            left_min[i] = p;       
        }
        
        // pass2: find the right_min at every index INCLUSIVE of current index
        vi right_min(heights.size(), heights.size());
        for(int j = heights.size()-2 ; j >=0; j--){
            int p =j+1;
            while(p <heights.size() && heights[p] >= heights[j]){
                p = right_min[p];
            }
            
            right_min[j] = p;
        }
            
        for(int i =0 ; i < heights.size(); i++){
            int temp = heights[i] *( right_min[i] - left_min[i] -1);
            max_area = max(max_area, temp);
            
        }
        
        return max_area;
        
    }
};

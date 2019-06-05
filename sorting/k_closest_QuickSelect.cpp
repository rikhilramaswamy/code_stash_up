

typedef vector<int> vi;
typedef vector< vi > vii;
typedef pair<int, int> npair;
typedef pair<float, npair> cus_pair;

typedef vector<cus_pair> vcp;
#define pb push_back 

class Solution {
public:
    
    float comp_distance(int x, int y){
        float res = (x*x) + (y*y);
        res = sqrt(res);

        return res;
    }
    
    int npartition(vcp & arr, int low , int high){
        float pivot = arr[high].first;
        
        int run =low;
        int cor_pos = low -1;
        while( run < high){
            if(arr[run].first < pivot){
                ++cor_pos;
                swap(arr[run], arr[cor_pos]);
                
            }
            run++;
        }
       
        swap(arr[cor_pos+1], arr[high]); // TODO this does not work for sorted list 
        
        return cor_pos +1;
    }
    
    
    
    void nquickselect(vcp & arr, int low, int high, int K ){
        if( low >= high){
            return;
        }
        
        int pivot = npartition(arr, low, high);
        
        int left_length = pivot - low +1;
        
        if(K < left_length ){
            nquickselect(arr, low, pivot-1, K);
        } else if ( K > left_length) {
            
            nquickselect(arr, pivot+1, high, K -left_length); // NOTE: that you are decrementing 
        }
        
        // if K == left_length (we have the set of K points which are nearest neighbors)
        
    }
    
    
    /*
    QuickSelect approach
    1) compute the distances of all the N points 
    2) now we need to use quickselect to select k points of our interest
    
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vii res;
        if( points.size() == 0 || K == 0){
            return res;
        }
        
        if(points[0].size() == 0)
            return res;
        
        vcp vcp1;
        
        for(int i =0; i < points.size() ; i++){
            auto  temp = points[i];
            float dist = comp_distance(temp[0], temp[1]);
            vcp1.pb(cus_pair(dist, npair(temp[0], temp[1])));
        }
        
        int end = (vcp1.size()-1);
        
        nquickselect(vcp1, 0, end , K);
        
        // finally get vcp1[0:k] is your answer; put it to res 
        
        for(int i=0; i < K ; i++){
            vi temp;
            temp.pb((vcp1[i].second).first);
            temp.pb((vcp1[i].second).second);
            res.pb(temp);
        }
        
        
        return res;
        
    }
};

#include <deque>
typedef deque<int> mydeq;
typedef vector<int> vi;
#define pb push_back


int valid_front(int cur_index, int k){
    return cur_index - k +1;
}
/*
 * Complete the function below.
 * Idea : dequeue of indices
 * add element to back of queue (if curr > deque_back remove all the eelements and then add curr)
 * deque.front always maintains the max_elem
 * REmove elements in invalid window from front of the queue
 */
vector <int> max_in_sliding_window(vector <int> arr, int w) {
    mydeq d1;
    vi res;
    
    
    for(int i=0; i < arr.size(); i++){
       // cout<<"\ncurrrent_index: "<<i;
        int cur_front = 0;
        if( !d1.empty()){
            cur_front = d1.front();
        }
        
        // add new element to queue
        // if curr_elem > deque 
        if(d1.empty()){
            d1.push_back(i);
        } else {
            if(arr[i] > arr[d1.back()]){
                // pop all the elems< curr from the deque and add curr
                while(!d1.empty() && arr[d1.back()] < arr[i] ){
                    d1.pop_back();
                }
                
            }
            d1.push_back(i);
        }
        
        // Make sure that queue contains only VALID window elems
        if(!d1.empty()){
            int valid_front_index  =valid_front(i, w); 
            while(!d1.empty() && d1.front() < valid_front_index){
                d1.pop_front();
            }
        }
        
         if(i+1 >= w) {
           //  cout<<"\n valid_window triggered";
            int temp_index = d1.front();
            res.pb(arr[temp_index]);
        }
    }
    
    
    return res;
}

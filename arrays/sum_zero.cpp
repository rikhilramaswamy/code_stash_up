// Complete the sumZero function below.
#include <unordered_map>


typedef unordered_map<long, long> myMap;
typedef pair <long,long> myMap_pair;
typedef vector<int> vi;
#define pb push_back

vector<int> sumZero(vector<int> arr) {
    // used to keep track of sum:index_seen
    myMap m1;
    vi res;
    
    // this is required for sub-aray like: { 2 ,-1,-1, 5} where answer is :{2,-1,-1}
    m1.insert(myMap_pair(0, -1));
    long runn_sum = 0;
    
    
    for(int i=0; i < arr.size(); i++){
        if(arr[i] == 0){
            res.pb(i);
            res.pb(i);
            return res;
        }
        runn_sum += arr[i];
        auto itr = m1.find(runn_sum);
        // check if sum was seen before 
        if(itr != m1.end()){
            // indices are low:itr->second+1, high: i
            int low_index = itr->second+1;
            res.pb(low_index);
            res.pb(i);
            return res;
        } else {
            m1.insert(myMap_pair(runn_sum, i));
        }
        
    }
    
    // no ZERO sum found
    res.pb(-1);
    return res;


}

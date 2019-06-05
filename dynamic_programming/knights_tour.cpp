#include <vector>
#include <unordered_map>

typedef vector<long> vi;
typedef vector<vi> vii;
typedef unordered_map<long, vi> mymap;
typedef pair<long, vi> mymap_pair;




// Complete the numPhoneNumbers function below.
long numPhoneNumbers(int startdigit, int phonenumberlength) {
    mymap map_neighbours;
    map_neighbours.insert(mymap_pair (0, {4,6} ));
    map_neighbours.insert(mymap_pair (1, { 6,8} ));
    map_neighbours.insert(mymap_pair (2, { 7,9} ));
    map_neighbours.insert(mymap_pair (3, { 4,8} ));
    map_neighbours.insert(mymap_pair (4, { 0,3,9} ));
    map_neighbours.insert(mymap_pair (5, { } ));
    map_neighbours.insert(mymap_pair (6, {0,1,7 } ));
    map_neighbours.insert(mymap_pair (7, {2,6} ));
    map_neighbours.insert(mymap_pair (8, {1,3 } ));
    map_neighbours.insert(mymap_pair (9, {2,4 } ));
    
    
    long phonenumberlength_internal = phonenumberlength -1; // basically N-1 
    // to naturally accomodate our base case of if n ==0 => return 1
    // Also since we have a DP table and matrices start with index 0 ; this 
    
    vii dp_table(phonenumberlength, vi(10, 0) );
    
    for(long i = 0 ; i < phonenumberlength; i++){
        
        for( long num=0; num <=9; num++){
            if( i ==0){
                dp_table[i][num] = 1;
                continue;
            }
            int sum =0;
            auto itr = map_neighbours.find(num);
            assert( itr != map_neighbours.end());
            auto npair = (*itr);
            
            vi neighbor_list = npair.second;
            
            for(auto e : neighbor_list){
                sum+= dp_table[i-1] [e];
            }
            
            dp_table[i] [num] = sum;
            
        }      
    }
    
    
    long res =0;
    auto itr = map_neighbours.find(startdigit);
    assert( itr != map_neighbours.end());
    auto npair = (*itr);

    vi neighbor_list = npair.second;
            
    for(auto elem : neighbor_list){
        res += dp_table[phonenumberlength -2] [elem];
    }
    return res;
}



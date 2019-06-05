#include<unordered_set>
#include<climits>

typedef unordered_map<char, int> myMap;
typedef pair<char, int> myMap_pair;
/*
this is an helper function which we can keep changing based on criteria
current criteria: String should have 2 distinct chars
variant: String can contain atmost two distinct chars
*/
bool valid_string(myMap & m1, int req_count){
    int uniq_cnt=0;
    for(auto elem: m1){
        if(elem.second != 0)
            ++uniq_cnt;
    }
    
    return req_count >= uniq_cnt;
    // NOTE: we return true for 2>1 ??
    // to eliminate special case for window containing one char only
    // we do NOT trigger shrink for one char string as it is valid 
}


/*
when to expand? Keep expanding as long as the string is valid_string
when to shrink? 
*/
int getLongestSubstring_helper(string & s, int k){
    
   
    myMap m1;
    int uniq_cnt=0;
    
    // do freq count of input 
    // for input validation
    for(auto e: s){
        auto itr = m1.find(e);
        if(itr == m1.end()){
            m1.insert(myMap_pair(e,1));
            uniq_cnt++;
        } else {
            itr->second++;
        }
    }
    // this block takes care of input: "a" => not enough distinct chars
    if(uniq_cnt < k ) 
        return 0;
    
    int st = 0;
    int curr_max = INT_MIN;
    myMap map1;

    for(int runner =0; runner < s.length(); runner++){
        auto itr = map1.find(s[runner]);
        if(itr == map1.end()){
            map1.insert(myMap_pair(s[runner] ,1));
        } else {
            (itr->second)++;
        }
       
        // shrink: when window string is invalid 
        // shrink from left
        while(!valid_string(map1, k)){
            auto itr = map1.find(s[st]);
            assert( itr != map1.end());
            --(itr->second);
            st++;
            
        }
        
        int cur_wind_len = runner - st +1;
        if(cur_wind_len >curr_max ){
            curr_max = cur_wind_len;
        }
        
        
    }
    
   if(curr_max == INT_MIN)
    return 0;
    
    return curr_max;
}




// Complete the getLongestSubstringLengthExactly2DistinctChars function below.
int getLongestSubstringLengthExactly2DistinctChars(string s) {
    
    int k =2; // number of unique chars

    return getLongestSubstring_helper(s, k);
}



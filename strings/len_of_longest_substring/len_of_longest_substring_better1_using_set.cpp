#include<unordered_set>
#include<climits>
typedef unordered_set<char> mySet;

/*
this is an helper function which we can keep changing based on criteria
current criteria: String should have 2 distinct chars
variant: String can contain atmost two distinct chars
*/
bool valid_string(mySet & s1){
    return s1.size() == 2;
}


/*
when to expand? Keep expanding as long as the string is valid_string
when to shrink? shrink only if the criteria fails AND 
                -- special case size(set) > 1 
                -- otherwise there is no point in shrinking "a" (one char string)
*/
int getLongestSubstring_helper(string & s){
    
    int st = 0;
    int curr_max = INT_MIN;
    mySet s1;
    for(int runner =0; runner < s.length(); runner++){
        
        s1.insert(s[runner]);
       // cout<<"\nst before: "<<st<<"\trunner: "<<runner;
        if(!valid_string(s1) && s1.size() > 1){
            s1.clear();
            s1.insert(s[runner]);
            st = runner;


            
            if((runner -1) >=0) { 
                s1.insert(s[runner -1]);
                int k = runner-1;
                for(; k >0 && s[k] == s[runner-1]; k--);
                
                // 012345678910
                // aaabbbbcccc
                // for loop is invoked (when runner=7 for above input)
                // set the st to correct position
                if(s[k] != s[runner-1]) {
                    assert(s[k+1] == s[runner-1]);
                    st = k+1;
                } else {
                    
                    st = k;
                }
                    
            } 
            
            
             /*s1.erase(s[st]);
            st++;*/
        }
        //cout<<"\nst AFTER: "<<st;

        // size of current window ( between st and runner)
        int temp = runner - st +1;
        if(valid_string(s1) && temp >curr_max ){
            curr_max = temp;
        }
        
    }
    
   if(curr_max == INT_MIN)
    return 0;
    
    return curr_max;
}




// Complete the getLongestSubstringLengthExactly2DistinctChars function below.
int getLongestSubstringLengthExactly2DistinctChars(string s) {

    return getLongestSubstring_helper(s);
}



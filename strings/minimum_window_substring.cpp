#include <unordered_map>
#include <assert.h>
typedef unordered_map <char, int> myMap;
typedef pair<char, int> myMap_pair;


bool valid_string(const myMap & m1,const  myMap &orig){
    
    for(auto elem: orig){
        auto itr = m1.find(elem.first);
        if(itr == m1.end()) {
            return false;
        } else {
            if(itr->second < elem.second)
            return false;
        }
        
    }
    
    return true;
}

/*
 * Complete the function below.
 */
string MinWindow(string strText, string strCharacters) {
    myMap orig;
    
    // record the char in original string (freq count)
    for(auto ch: strCharacters){
        auto itr = orig.find(ch);
        if( itr == orig.end()){
            orig.insert(myMap_pair(ch, 1));
        } else {
            (itr->second)++;
        }
    }
    
    
    int st = 0; 
    int curr_min = INT_MAX;
    myMap map1;
    int runner =0 ;// start of window 
    int string_start =0;
    int end =0; // end of min-found 
    for(; runner < strText.length(); runner++){
       // cout<<"\n for loop  runner: "<<runner<<"\t st: "<<st<<"\n";
        // include current char in map1
        // EXPANDING: as long as string is INVALID
        auto itr = map1.find(strText[runner]);
        if( itr == map1.end()){
            map1.insert(myMap_pair(strText[runner], 1));
        }else {
            (itr->second)++;
        }
        
        if(valid_string(map1, orig)) {
        
            // string is valid : SHRINK to make it shorter as possible
             while(valid_string(map1, orig)){
                //cout<<"\n runner was: "<<runner<<"\tst: "<<st<<"\n";
                auto itr2 = map1.find(strText[st]);
                assert(itr2 != map1.end());
                --(itr2->second);
                 ++st;
            }
        
            //make it a valid string 
             // set st to correct position 
            // add the last removed char back to map1
            --st;
            auto itr1 = map1.find(strText[st]);
            // assert( itr1 != map1.end()); Q) Why is this failing ?
             //(itr1->second)++;
             if( itr1 == map1.end()){
                 map1.insert(myMap_pair(strText[st], 1));
            }else {
                 (itr1->second)++;
            }
        
        }
        // record the min string so far 
        if(valid_string(map1, orig)) {
            //cout<<"\n trig1";
            int curr_len = runner - st +1;
            //cout<<"\n runner was: "<<runner<<"\tst: "<<st<<"\n";

            if(curr_len < curr_min) {
              // cout<<"\n trig2\tcurr_len: "<<curr_len<<"\n";;
                curr_min = curr_len;
                string_start = st;
                end = runner;
            }
        }
        
    }
    
    //cout<<"\nend: "<<"\t start: "<<string_start<<"\n";
    //cout<<"\ st: "<<st<<"\t end: "<<end<<"\n";
    if(curr_min == INT_MAX)
        return "";
    
    //cout<<"\nend: "<<"\t start: "<<st<<"\n";
    string min_string = strText.substr(string_start, end-string_start+1);
    //cout<<"\nmin_string: "<<min_string<<"\n";
    return min_string;

    

}



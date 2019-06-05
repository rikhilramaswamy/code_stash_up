#include<unordered_set>
#include<climits>
typedef unordered_set<char> mySet;

int getLongestSubstring_helper(string & s){
    int curr_max = INT_MIN;
    for(int i =0; i < s.length(); i++){
        mySet s1;
        for(int j = i; j < s.length(); j++){
             s1.insert(s[j]);
             if(s1.size() == 2){
                int temp = j-i+1;
                if(temp > curr_max)
                    curr_max = temp;
             }
        }
    }
    
    //cout<<"\n curr_max: "<<curr_max;
    if(curr_max == INT_MIN)
        return 0;
    
    return curr_max;
}




// Complete the getLongestSubstringLengthExactly2DistinctChars function below.
int getLongestSubstringLengthExactly2DistinctChars(string s) {

    return getLongestSubstring_helper(s);
}



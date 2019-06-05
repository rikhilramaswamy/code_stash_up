/*
 * Complete the 'pattern_matcher' function below.
 *
 * The function accepts STRING text and pattern as parameter and returns BOOLEAN.
 */

bool pattern_matcher_helper(string strText,string strPattern, int t_index , int reg_index ){
    
    
    // base cases
    // empty string so it is a match
    if( t_index < 0 &&  reg_index < 0)
        return true;
        
    // only exclude ; there is nothing to pick (string is exhausted)
    if(t_index < 0 && strPattern[reg_index]  == '*')
        return pattern_matcher_helper(strText, strPattern, t_index, reg_index -2);
        
    if(reg_index < 0) return false;
    
    
    // transitions
    if (reg_index > 0 && strPattern[reg_index] == '*'){
        
        if(strPattern[reg_index -1] == '.' ||strPattern[reg_index-1] ==  strText[t_index]){
            // BOTH include and exclude case
            return ( pattern_matcher_helper(strText, strPattern,t_index, reg_index -2) || pattern_matcher_helper(strText, strPattern,t_index -1, reg_index)); 
        }
        // exclude case`
        return pattern_matcher_helper(strText, strPattern,t_index, reg_index -2);
        
    }
    
    if( t_index >=0 && reg_index>=0) {
        if(strPattern[reg_index] == '.' || strPattern[reg_index] == strText[t_index])
            return pattern_matcher_helper(strText, strPattern,t_index-1, reg_index-1);
        
    }
    
  
  return false;
  
  
}


bool pattern_matcher(string text, string pattern) {
    
    if(text.empty() && pattern.empty() )
        return true;
    int i = text.length() -1;
    int j = pattern.length() -1;
    //cout<<"\n i: "<<i<<"\t j: "<<j;
    
    return pattern_matcher_helper(text, pattern, i, j);
}




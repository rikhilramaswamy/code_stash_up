
/*
 * Complete the function below.
 */
int find_max_length_of_matching_parentheses(string brackets) {
    
    /* pass1: left to right 
    if open == close we have a potential answer(balanced parenthesis) ; record max length balanced 
    reset both when close > open */
    
    int open =0;
    int close =0;
    int max_len= 0;
    
    //cout<<"\n brackets-len:"<<brackets.length();
    
    for(auto e :brackets ){
         if(e == '(')
            ++open;
        else if(e == ')' )
            ++close;
       
       //cout<<"\nopen :"<<open<<"\t close: "<<close<<"\n";
        if (open == close ){
            max_len = max(open +close , max_len);
        }
        if(close > open){
            open =0;
            close =0;
        }
      
    }
    
    //cout<<"\nmax_len :"<<max_len<<"\n";

    
    open =0; close=0;
    /*  pass2: right to left
    reset both when open > close ; because when moving from right to left
    there is NO way you can find a balanced parenthesis if open > close*/
    for(int i = brackets.length()-1; i>=0; i--){
        
         if(brackets[i] == '(' )
            ++open;
       else if(brackets[i] == ')')
            ++close;
            
        if (open == close ){
            max_len =max(open +close , max_len);
        }
        if(open > close){
            open =0;
            close =0;
        }
        
        
    }
    
    return max_len;
}


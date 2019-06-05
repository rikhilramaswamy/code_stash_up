#include <vector>
#include <stack>
#include <cmath>

typedef vector<int> vi;
typedef stack<int> si;
#define pb push_back

string int_to_string(long long int num){
    if (num == 0)
	{
		return "0";
	}
    
    
    string res;
    while(num != 0){
        int temp = num % 10;
        //res = string(temp + '0') + res;
        res+= (temp + '0');
        num = num/10;
    }
    
    string final (res.rbegin(), res.rend());
    return final;
}

long long int string_to_int(string & str){
    
    long long int num =0;
    for(int i=0; i < str.length(); i++) {
        num = num*10 + (str[i] - '0');
    }
    
    return num;
}

bool all_digit_nines(string & str){
    bool res = true;
     for(int i=0; i < str.length(); i++) {
         int temp = str[i] - '0';
         if(temp != 9)
            return false;
     }
     
     return true;
}

long long int copy_left(string & str, int l , int r){
    while(l >=0){
        str[r] = str[l];
        --l;
        ++r;
    }
    
    return string_to_int(str);

}

long long int inc_mid_copy_left(string &str, int l, int r){
    str[l]++;
    
    while (l >=0){
        int temp = str[l] - '0';
        
        // check if there is an overflow; our range [0-9]
        // if so propagate carry
        if(temp >= 10){
         str[l-1]++;
         str[l] = (str[l] - '0') % 10 + '0';
         
        }
        
        str[r] = str[l];
        --l;
        ++r;
    }
    return string_to_int(str);
    
}

/* idea is to start from middle and move towards the ends */
long long int next_palindrome_helper(string & str){

    int len = str.length();
    int l,r;
   
    // point the l,r to middle 
    // if even 
    if((len % 2) == 0){
        r = len /2;
        l = len/2 -1;
        
    } else {
        // odd length (noth l and r wil point to same element)
        r = len/2;
        l =len/2;
    }
    

    if (len ==1){
        r = 0;
        l= 0;
        return string_to_int(str)+1;
    }
   
    int copy_l = l;
    int copy_r = r;
    // find the first mismatch
    while (copy_l <= copy_r && str[copy_l] == str[copy_r] ){
        --copy_l;
        ++copy_r;
    }
    
    // input string is a palindrome
    if(copy_l < 0 ){
        return inc_mid_copy_left( str,  l ,  r);
    }
    
    // we have str[l] and str[r] as MISMATCH 
    if(str[copy_l] > str[copy_r]){
        return copy_left( str, copy_l , copy_r );
    }else {
        return inc_mid_copy_left( str,  l ,  r);
    }
    
}

/*
 * Complete the function below.
 */
long long int next_palindrome(int n) {
    

    string s1 = int_to_string(n);

    if(all_digit_nines(s1)){
        long long int temp = pow(10, s1.length());
        ++temp;
        return temp;
    }
    
    return next_palindrome_helper(s1);
}



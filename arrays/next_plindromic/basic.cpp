#include <vector>
#include <stack>

typedef vector<int> vi;
typedef stack<int> si;
#define pb push_back

void next_palindrome_helper(vi &a){
    int l = 0;
    int r = a.size()-1;
    int carry =0;
    while(l <= r){
       // cout<<"\n start l: "<<l<<"\t r: "<<r<<"\tcarry: "<<carry<<"\n";
        int prev_carry = carry;
        carry = (a[r] + carry) / 10;
        int curr_r = r; // this is used to set next_r
       
        bool overflow = false;
       // overflow case 
        // use r to set the correct l 
        while ( r>=0 && carry == 1 ){
            overflow = true;
            a[r] = (a[r] + carry) % 10;
            --r;
            carry = (a[r] + carry) / 10;
        }
       
        if (overflow) { 
           // cout<<"\n overflow block invoked";
            a[r] = a[r] +1;
            l = r;
            r = curr_r+1;
            overflow = false;
        } else {
           //cout<<"\n NO overflow block with prev_carry: "<<prev_carry<<"\n";

        // no overflow so add carry and RESET it
            a[r] = a[r] +prev_carry;
            carry =0;
        }
        // set correct next_l and next_r
        //a[r] = a[r] + carry;
        //carry =0;
        // left elem > right
        if(a[l] > a[r]){
            //cout<<"left elem > right\n";
            a[r] = a[l];
        }else if(a[r] > a[l]){
            // right elem > right
            carry = 1;
            //cout<<"right elem > right with carry: "<<carry<<"\n";

            int temp_r = r-1;
            int temp_l = l +1;
            // we are at the end ; so we can NO longer propagate carry
            if(temp_l > temp_r){
                int temp = a[l]+1;
                
                a[l] = temp;
                a[r] = temp;
            }else {
                a[r] = a[l];
            }
            
            //a[r] = a[l];
        } 
        
        --r;
        ++l;
    }
    
}


/*
 * Complete the function below.
 */
long long int next_palindrome(int n) {
    si ms;
    vi cvec;
    
    int m = n+1;
    while(m !=0 ){
        int rem = m %10;
        m = m/10;
        ms.push(rem);
    }
    
    while(!ms.empty()){
        int res = ms.top();
        cvec.pb(res);
        ms.pop();
    }
    
    /*cout<<"\n number was :";
    for(auto e: cvec){
        cout<<"\t " << e;
    }
    cout<<"\n number END\n";*/

    next_palindrome_helper(cvec);
    long long int res =0;
    
    for(auto e: cvec){
        res = (res *10) + e;
    }
    
    return res;
}

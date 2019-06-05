typedef vector<string> vs;
#define pb push_back


/*
Given a string containing one IP address; 
goal: is to return all valid IP address combinations that can be formed using the given string
constraints: 
there are 4 quadrants 
each quadrant should have min 1 number 
max three chars: < 256 
All the given characters should be used 
All the given chars should be used in the SAME order


soln: recursion with backtracking
states: quadrant, index, vs & result, vs& sofar
base_case:
if( quadrant == 4 && index == orig.size())
// add sofar to result
transitions:
for( int i =1 ; i <=3 ; i++)
check if the chosen number is valid ip: This check only needs to convert string to integer : std:stoi() can be used
if so continue

*/

class Solution {
public:
    bool valid_ip_helper(int int_ip, string str_ip){
        int int_ip_cpy = int_ip;
        int num_digits=0;
        while(int_ip >0){
            int_ip = int_ip/10;
            ++num_digits;
        }
        
        if(int_ip_cpy == 0 )
            num_digits =1;
        
        //cout<<"\n num_digits: "<<num_digits<<"\t str_ip:"<<str_ip.size();
        if(num_digits == str_ip.size())
            return true;
        
        return false;
        
    }
    
    void restoreIpAddresses_helper(int index, int quadrant, string &orig, vs & result, vs &sofar ){
        //cout<<"\n restoreIpAddresses_helper invoked with index: "<<index<<"\t quad: "<<quadrant<<"\t orig: "<<orig;
        if(quadrant >= 4){
            if(index == orig.size()){
                string t ="";
                assert(sofar.size() == 4);
                for(int i =0 ; i <=3; i++){
                    if(i == 3){
                        t += sofar[i] ;
                        continue;
                    }
                    t += sofar[i] + ".";
                }
                
                result.pb(t);
            }
            return;
        }
        
        string temp;
        for(int i=1; i <=3 && ((index + i) <= orig.size()); i++){
            temp = orig.substr(index, i);
            
            int temp_ip = stoi(temp);
            if(temp_ip >=0 && temp_ip <256 && valid_ip_helper(temp_ip, temp)) {
                sofar.pb(temp);
                restoreIpAddresses_helper(index + i, quadrant+1, orig, result, sofar);   
            }
            
            // pop_back from sofar ONLY if you had added the quadrant result before
            // in otherwords only if the temp_ip was valid-ip, you need to pop ; ELSE no need
            if(sofar.size() == (quadrant+1) ){
                sofar.pop_back();
            }
                   
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        vs result;
        vs sofar;
        
       restoreIpAddresses_helper(0, 0, s, result, sofar);
        
        /*int res = stoi("111");
        bool temp = valid_ip_helper(1, "0010");
        cout<<"\n res is :"<<res<<"\n temp: "<<temp;*/
        
        return result;
    }
};

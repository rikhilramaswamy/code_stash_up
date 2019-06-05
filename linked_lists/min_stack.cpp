#include <stack>
#define pb push_back

typedef stack<int> si;
typedef vector<int> vi ;
typedef pair<int, int> pi;
typedef stack<pi> spi;

class MinStack{
    private:
        si *s1; //main stack
        spi *ms; // MINStack
    
    public:
        MinStack(){
            s1 = new si();
            ms = new spi();
        }
        
        void push(int elem){
            s1->push(elem);
            
            if(ms->empty()){
               ms->push(pi(elem, 1));
            } else {
                pi temp = ms->top();
                if (elem < temp.first){
                    ms->push(pi(elem, 1));
                }else if(elem == temp.first){
                    // element is equal to top
                    // increase the ref_count and add it again (pop and add)
                    ms->pop();
                    ++(temp.second);
                    ms->push(temp);
                    
                }
            }
            
        }
        
        int pop(){
            int res= -1;
            
            if(!s1->empty()){
                res = s1->top();
                s1->pop();
                pi pitemp = ms->top();
                if(pitemp.first == res){
                    ms->pop();
                    if(pitemp.second >=2){
                        // decrement index and push 
                        --(pitemp.second);
                        ms->push(pitemp);
                    }
                }
            }
            
            return res;
        }
        
        int min(){
            int res = -1;
            if(!ms->empty()){
                return (ms->top()).first;
            }
            
            return res;
            
        }
        
};

/*
 * Complete the function below.
 */
vector<int> min_stack(vector<int> operations) {
    MinStack* prim = new MinStack();
    vi final;
    
    for(auto e: operations){
        int res;
        switch(e){
            
            case-1: prim->pop();
                     break;
            case 0: res = prim->min();
                    final.pb(res);
                    break;
            default:
                    prim->push(e);
                    break;
        }
        
    }
     
    return final;
    
}



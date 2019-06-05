#include <algorithm>
#include <queue>
typedef vector<int> vi;
typedef set<int> si;
#define pb push_back
#define cont_tr(container, it) \
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)
using namespace std;

/*
 * Complete the function below.
 */

/*
vector <int> topK(vector <int> arr, int k) {
        typedef priority_queue<int, vi, greater<int> > pq; // min_heap
        pq mypq;
         int n = arr.size();
        vi res;
        
        if(arr.empty()) return res;
        
        int i =0;
        
        si myset;
      
        
        for( ; i < n ; i++) {
            
            decltype(myset.begin()) it = myset.find(arr[i]);
            if(it != myset.end())
                continue;
                
            if(myset.size() == k) {
                 int temp = mypq.top();
                 if(arr[i] > temp){
                    mypq.pop();
                    myset.erase(temp);
                    mypq.push(arr[i]);
                    myset.insert(arr[i]);
                 }       
            } else {
                mypq.push(arr[i]);
                myset.insert(arr[i]);
                
            }
        }
    
         
         while(!mypq.empty()) {
             int elem = mypq.top();
             mypq.pop();
             res.pb(elem);
             myset.insert(elem);
             
         }
    
          vi newv(myset.begin(), myset.end());
         
             return newv;
    
         
        
    
}
*/

#include <unordered_set>
typedef priority_queue<int, vector<int> , greater<int> > mypq;
typedef unordered_set<int> myset;
vector <int> topK(vector <int> arr, int k) {
    
    vi res;
    if(arr.empty())
        return res;
    
    myset set1;
    mypq   pq1;
    for(int i=0; i < arr.size(); i++){
        auto temp = set1.find(arr[i]);
        
        if(temp == set1.end()) {
           if(pq1.size() == k) {
               if(pq1.top() < arr[i]){
                   pq1.pop();
                    pq1.push(arr[i]);
                    set1.insert(arr[i]);   
               }
                
     
           } else {
               pq1.push(arr[i]);
               set1.insert(arr[i]);
               
           }
            
            
        }
        
        
    }
    
    
    while(!pq1.empty()) {
        res.pb(pq1.top());
        pq1.pop();
        
    }
    
    return res;
}



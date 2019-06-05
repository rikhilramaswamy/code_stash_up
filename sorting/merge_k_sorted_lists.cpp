typedef vector<int> vi;
typedef vector< vi> vii;
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)
#define pb push_back
typedef pair<int, int> mypair;

class mycomparison
{
  bool reverse;
  vii arr1;
public:
  mycomparison(const vii & arr,const bool& revparam=false)
    {
      reverse=revparam;
        arr1 = arr;
  }
  bool operator() (const mypair& lhs, const mypair&rhs) const
  {
      const vi & left_arr = arr1[lhs.second];
      const vi & rght_arr = arr1[rhs.second];
      
      int left = left_arr[lhs.first];   
      int right =  rght_arr[rhs.first];
      
      if (reverse) return (left > right);

      return (left < right);
  }
};





vector <int> mergeArrays(vector < vector<int> > arr) {
     vi res;
    bool flag = true;
    vi & v1 = arr[0];
    
    if(arr.empty()) {
        return res;
    }
    
    if(v1.size() >= 2){
        if(v1[0] > v1[v1.size()-1])
            flag = false;
    }
    
   
    int k = arr.size();
    int n = v1.size();
    
    typedef priority_queue<mypair,std::vector<mypair>,mycomparison> mypq_type;
    mypq_type  myq(mycomparison(arr, flag));
    
    for(int i =0; i < k ; i++) {
        myq.push(mypair(0, i));
    }
        
    while(!myq.empty()) {
                  mypair temp_res = myq.top();
                 myq.pop();
                
                vi & temp = arr[temp_res.second];
                int val1 = temp[temp_res.first];
                
                 res.pb(val1);
              
               if(temp_res.first < (n-1)){
                 int tempp = ++(temp_res.first);
                 myq.push(mypair(tempp,temp_res.second ));
               }
    }
    
    return res;
}


/*
#include <queue>
typedef pair< int, int> npair;
typedef vector<int> vi;
typedef vector<vi> vii;
#define pb push_back


class sample {
  bool reverse;
  vii param;
    
    public: 
    sample(vii & refer, bool direc){
        param = refer;
        reverse = direc;
    }
    
    bool operator() (const npair & p1, const npair & p2  ){
        vi v1 = param[p1.first];
        vi v2 = param[p2.first];
        
        if(reverse) { return v1[p1.second] > v2[p2.second];}
        
        return v1[p1.second] < v2[p2.second];
  
    }
    
    
};

typedef priority_queue<npair, vector<npair>, sample> mypq;





vector <int> mergeArrays(vector < vector<int> > inp) {
     vi res;
    if(inp.empty())
        return res;
    
    bool reverse = true;
    
    if(inp[0].size() >=2){
        vi v1 = inp[0];
        if(v1[0] > v1[v1.size() -1])
            reverse = false;
        
    }
      
    //cout<<"\n reverse is:"<<reverse;
    mypq pq1(sample(inp,reverse));
    int k = inp.size();
    int n = inp[0].size();
    //cout<<"\nk =="<<k<<"\t n=="<<n;
    
    for(int i =0; i < k ; i++)
        pq1.push(npair(i, 0));

    
        while(!pq1.empty()) {
        
        npair  temp = pq1.top();
        //cout<<"\ntemp->first: "<<temp.first<<"\t temp.second: "<<temp.second;
        vi & vec = inp[temp.first];
        //cout<<"\n number being pushed is: "<<vec[temp.second];
        res.pb(vec[temp.second]);
        
        pq1.pop();
        
        if(temp.second < n-1){
            int res = ++(temp.second);
            pq1.push(npair(temp.first, res));
        }
        
         }
        
   
    
    
    return res;
}*/

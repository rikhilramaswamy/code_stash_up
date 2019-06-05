typedef vector<int> vi;
typedef vector< vi> vii;
typedef pair<int, int> npair;
typedef pair<float, npair> cus_pair;
typedef vector<cus_pair> vcp;
#define pb push_back

class ncompare {
  public:
    ncompare () { }
    bool operator() (cus_pair & p1, cus_pair & p2 ){
        if(p1.first <= p2.first)
            return true;
        
        return false;  
    }
     
};

typedef priority_queue< cus_pair, vector<cus_pair> , ncompare > myPQ;
class Solution {
public:
    
    float comp_distance(int x, int y){
        float res = (x*x) + (y*y);
        res = sqrt(res);
        
        return res;
    }
    
    /*
    Approach1: T: O( n log n); S: O(N)
    min-PQ of floats 
    iterate through input vector and compute the distance from origin(0,0) to given point
    Add distance on PQ 
    
    Approach2: T: O( n log k ) ; S:O(N)
    a) Max PQ (size K)  of floats 
    b) iterate through input vector and compute distance from Origin(0,0) and store them in a vector 
    c) now iterate through dist vector and add the item onto PQ only if 
        c1) new element is lesser than MAx-PQ top() OR
        c2) PQ has lesser than k elements 
        
    d) finally, your PQ will have k closest neighbors
    
    */
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vii res;
       
        if(points.size() == 0 || K ==0)
            return res;
        
        if(points[0].size() == 0)
            return res;
        
        vcp vcp1;
        myPQ pq1;
        
        
        //iterate through input vector and compute distance from Origin(0,0) and store them in a vector 
        for(int i =0; i < points.size(); i++){
            vi & temp = points[i];
            assert(temp.size() == 2);
            float dist = comp_distance(temp[0], temp[1]);
            
            vcp1.pb(cus_pair(dist, npair(temp[0], temp[1])));
           // pq1.push(cus_pair(dist, npair(temp[0], temp[1])));
           // pq1.push(dist);
        }
            
        // now iterate through dist vector and add the item onto PQ only if 
        for(auto elem: vcp1){
            if(pq1.size() < K){
                pq1.push(elem);
                continue;
            }
            
            auto pqtop = pq1.top();
            if(elem.first < pqtop.first){
                pq1.pop();
                pq1.push(elem);
            }
        }
        
        assert(pq1.size() == K);
        while(!pq1.empty()){
            auto elem = pq1.top();
            pq1.pop();
            vi temp ;
            temp.pb(elem.second.first);
            temp.pb(elem.second.second);
            res.pb(temp);   
        }
        
        
        return res;
    }
};

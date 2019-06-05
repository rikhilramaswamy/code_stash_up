typedef vector<char> vc;
typedef vector<string> vs;
typedef unordered_map<char, vc> myMap;
typedef pair<char, vc> myMap_pair;
typedef stack<char> sc;

typedef unordered_map<char, int> visited;
typedef pair<char, int>visited_pair;
/* 0:undiscovered 1:discovered 2:visited*/
#define pb push_back


class Solution {
public:
    /*
    we need order/sequence so top-sort 
    explicit graph
    BFS/DFS: DFS is simpler
    node: chars 
    edges: a->b=> a comes before b  (directed graph)
    visited: global visited should  suffice
    */
    
    void construct_graph(myMap &m1, const vs & words){
        
        
        // add all the unique chars added onto map 
        for(int i=0; i <words.size(); i++){
            for(auto e: words[i]){
                auto itr = m1.find(e);
                if(itr == m1.end()){
                    vc temp;
                    m1.insert(myMap_pair(e, temp));
                }
                
            }
        }
        
        
        for(int i=0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int k =0; int m =0;
            
            while(k < s1.length() && m < s2.length()){
                
                if(s1[k] != s2[m]){
                    break;
                }
                ++k;
                ++m;
            }
            
            // NTODO: do we need to handle anything here
            if(k == s1.length() && m == s2.length()){
                continue;
            }
            
            if( k != s1.length() && m != s2.length() ){ 
                // add edge s1[k] and s2[m]
                auto itr = m1.find(s1[k]);
                
                assert(itr != m1.end());
                (itr->second).pb(s2[m]);
            
                auto itr2 = m1.find(s2[m]);
                if(itr2 == m1.end()){
                    vc temp2;
                    m1.insert(myMap_pair(s2[m], temp2));
              
                }   
           }
         /*
         CASE3: k!= s1.length() but m == s2.length()
         CASe4: m != s2.length() but  k == s1.length()
         case3 and case4 are NOTneeded as we have added all unique chars in the strings onto map ALREADY
          */
        }
    }
    
    
    bool dfs(char c,myMap &m1, visited & track, sc &sc1 ){
        auto itr = track.find(c);
        assert(itr != track.end());
        itr->second = 1; // mark it discovered
        
        // for each of the neighbors 
        auto itrm = m1.find(c);
        assert(itrm != m1.end());
        auto & neighbors = itrm->second;
        for(auto e: neighbors){
            auto ft = track.find(e);
            assert(ft != track.end());
            if(ft->second == 1){
                return false;
            }
            
            if(ft->second == 0){
                if(!dfs(e, m1, track, sc1))
                    return false;
            }
        }
        
        sc1.push(c);
        itr->second = 2; // node is visited
        // add to sc1 
        return true;
        
    }
    
    
    bool dfs_main(myMap &m1, visited & track, sc &sc1){
        
        for(auto elem: m1){
            auto itr = track.find(elem.first);
            assert(itr != track.end());
            
            if(itr->second == 0){
                if(!dfs(elem.first, m1, track, sc1)){
                    return false;
                }
                
            }
            
        }
        
        return true;
    }
    
    
    
    string alienOrder(vector<string>& words) {
        myMap m1;
        construct_graph(m1, words);
        sc sc1;
        
        visited track;
        // init all the visited elems:0
        for(auto elem: m1){
                track.insert(visited_pair(elem.first, 0));
        }
        
        // if cycle exists there cannot be valid top-sort 
        if(!dfs_main(m1, track, sc1))
            return "";
        
        string res;
        
        while(!sc1.empty()) {
            res += sc1.top();
            sc1.pop();
        }
        
        return res;
        
    }
};

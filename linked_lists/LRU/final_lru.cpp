#include<list>
using namespace std;
typedef pair<int, int> npair;
typedef unordered_map<int, list<npair>:: iterator> myMap;
typedef pair<int, list<npair>:: iterator >myMap_pair;

class LRUCache {
private:
    list<npair> myList;
    myMap m1;
    int max_num;
public:
    
    LRUCache(int capacity) {
        max_num = capacity;
    }
   
    int get(int key) {
        int res =-1;
        auto itr = m1.find(key);
        if(itr == m1.end())
            return res;
        
        res = (itr->second)->second;
        myList.erase(itr->second);
        
        myList.push_front(npair(key, res));
        
        itr->second = myList.begin();
        return res;
        
    }
    

    void put(int key, int value) {
        /* if so : remove the DLL at the tail + remove associated key from map 
                             then add new node to DLL + add to map 
        ELSE: add new node to DLL + add to map*/
        
        auto itr = m1.find(key);
        
        // if key exists update value and move to front 
        if(itr != m1.end()){
            
            // remove from original list 
            myList.erase((itr->second));
            // add to front
            myList.push_front(npair(key, value));
            // update the map
            itr->second = myList.begin();
            return;
            
        }
        
        // check if capacity reached 
        // if so remove LRU element 
        if(m1.size() == max_num){
            auto itr = myList.back();
           // assert(itr != myList.end());
            myList.pop_back();
            // remove from map
            m1.erase(itr.first);
        }
        
        assert(m1.size() < max_num);
        
        // add new element to front
         myList.push_front(npair(key, value));
        m1.insert(myMap_pair(key, myList.begin()));
       
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

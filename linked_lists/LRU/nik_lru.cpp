using namespace std;

class LRUCache {
private:
    class node;
    unordered_map<int, node*> m1;
    int max_num; 
    class node {
      public:
        int val ;
        int key;
        node * next;
        node * prev;
        
        node(int v, int k){
            val = v;
            key = k;
            next = NULL;
            prev = NULL;
        }
    };
public:
     node* front ;
     node * back;
    /*
    get():
        check if key exists => if so MOVE the DLL node to the front 
        if key does NOT exist => return err
        ..........
        Basically instead of MOVING the read node to front (delete it + add_to_front)
        delete_node 
        add_to_front()
        
    put(k, v):
        check if map-full => if so : remove the DLL at the tail + remove associated key from map 
                             then add new node to DLL + add to map 
        ELSE: add new node to DLL + add to map
        
        .......
        if cap_not_full
            add_to_front()
            
        else
            delete LRU node 
            add_to_front(): new element 
            
    Add_to_front()
        if (front == NULL)// DLL is empty
             make new as both front and tail
         else 
            new->next = front 
            front->prev = new 
            front = new 
    Delete_node()
        node could be in the front 
        back
        middle 
    
    */
    
    LRUCache(int capacity) {
        max_num = capacity;
        front = NULL;
        back = NULL;
;
    }
    void add_to_front(node * t){

        // if DLL is empty 
        if(front == NULL){
            front = t;
            back = t;
            
        } else{
            t->next = front;
            front->prev = t;
            front = t;
        }
        // add to map also 
        m1.insert(pair<int, node*>(t->key, front));
     }
    
    void delete_node(node * t){
        // node in front
        //node in back
        // node in middle 
        // only one node in DLL (rest front and back properly)
        
        if(t->next != NULL){
            t->next->prev = t->prev;
        }
        
        if(t->prev != NULL){
            t->prev->next = t->next;
        }
        
        //missed this use case (when only ONE node is left)
        if( front == back) {
            front = NULL;
            back = NULL;
        } else if( t == front){
            front = t->next;
        } else if( t == back) {
            back = t->prev;
        }
        
        // delete from the map 
        m1.erase(t->key);
        // delete the DLL
        delete t;
    }
    
    int get(int key) {
        auto itr = m1.find(key);
        if(itr == m1.end())
            return -1;
        
        //delete_node 
        node *t = itr->second;
        int val = t->val;
        delete_node(t);
        //add_to_front()
        node * temp = new node(val, key);
        add_to_front(temp);
        return val;
    }
    

    void put(int key, int value) {
        /* if so : remove the DLL at the tail + remove associated key from map 
                             then add new node to DLL + add to map 
        ELSE: add new node to DLL + add to map*/
        auto itr = m1.find(key);

        if(itr == m1.end()) {
            // if we are at capacity ; DELETE LRU node (back)
            if(m1.size() == max_num){
                delete_node(back);
            }
            node * temp = new node(value, key);
            add_to_front(temp);
            return;  
        }
        
        delete_node(itr->second);
        node * temp = new node(value, key);
        add_to_front(temp);
    }   
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

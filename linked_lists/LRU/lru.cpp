#include <unordered_map>
//class nlru;
//class nlru::dllnode;
//typedef unordered_map<int, nlru::dllnode*> myMap;
//typedef pair<int, dllnode*> myMap_pair;
typedef pair<int,int> npair;
typedef vector<int> vi;

#define pb push_back

class nlru{
public:
    class  dllnode{
    public:
        pair<int, int> np;
        dllnode *next;
        dllnode *prev;
        
        dllnode(npair newone){
            np.first = newone.first;
            np.second = newone.second;
            next = NULL;
            prev = NULL;
        }
      
  };

  nlru(int cap){
      map_capacity = cap;
      curr_cap =0;
      front = NULL;
      back = NULL;
  }
  
  
 private:
  dllnode *front;
  dllnode *back;
  //myMap m1;
  unordered_map<int, dllnode*> m1;
  int map_capacity;
  int curr_cap;
  
  public: 
  
  void set(int key, int value){
      
      if(m1.empty()){
          //cout<<"\n m1 seems empy; lets add key: "<<key<<"\t valu: "<<value;
          
          // you need to add a new entry
          npair np1(key, value);
          dllnode * n = new dllnode(np1);
          front =n;
          back = n;
          m1.insert(std::make_pair(key , n));
          ++curr_cap;
      } else {
          //cout<<"\n checking if key: "<<key;
          // check if the entry exists 
          auto itr = m1.find(key);
          
          // exists; update value
          if(itr != m1.end()){
              dllnode * temp = itr->second;
              npair & np1 = temp->np;
              np1.second = value;
              
              // move this to the front to make it MRU
              // TODO: Do we have to check for non-null here??
              // if only one element in DLL NOthing to do
              // if temp == front => nothing to do 
              if(temp == front){
                  // notthing to do
              } else if (temp->next != NULL && temp->prev != NULL){
                 temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
              
                temp->next= front;
                front->prev = temp;
                front = temp;
              } else if( temp->next == NULL){
                  // temp is the last node
                  temp->prev->next = NULL;
                  back = temp->prev;
                
                temp->next= front;
                front->prev = temp;
                front = temp;
              }
          } else {
              // delete LRU 
             //cout<<"\n trying to delete element: curr_cap: "<<curr_cap<<"\t map_cpacity: "<<map_capacity<<"\n";
              if(curr_cap == map_capacity) {
                  //cout<<"\n entered cleanup block";
                 //assert(back != NULL);
                 assert(front != NULL);
                  //  cout<<"\n POST assert  cleanup block";

                  dllnode * fordel = back;
                 
                  // if only one element in DLL
                  if(front == back ){
                  //if(curr_cap == 1){
                      front = NULL;
                      back = NULL;
                  } else {
                    fordel->prev->next = NULL;
                    back = fordel->prev;
                    
                  }
                  
                  if(fordel != NULL)
                    m1.erase((fordel->np.first));
                  delete fordel;
                  --curr_cap;
              }
              // add new element to the front
              npair np1(key, value);
              dllnode *n = new dllnode(np1);
              n->next = front;
              if(front != NULL)
                front->prev = n;
              front = n;
              m1.insert(std::make_pair(key , n));
              // insert onto hashmap
              ++curr_cap;
          }
      }
      
      
  }
  
  int get(int key){
      int res =-1;
      //cout<<"\n request to get key: "<<key;
      //cout<<"\n m1-size: "<<m1.size();
      auto itr = m1.find(key);
      if(itr != m1.end()){
         // cout<<"\n iterator is NON-null!!";
          dllnode * temp = itr->second;
          res = temp->np.second;
          if (temp == front || curr_cap == 1 ){
              //cout<<"\nres was: "<<temp->np.second<<"\n";
              return temp->np.second;
          } else {
              // move to the front
               if (temp->next != NULL && temp->prev != NULL){
                 temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
              
                temp->next= front;
                front->prev = temp;
                front = temp;
              } else if( temp->next == NULL && temp->prev != NULL){
                  // temp is the last node
                  temp->prev->next = NULL;
                  back = temp->prev;
                
                temp->next= front;
                front->prev = temp;
                front = temp;
             }
         }
      }
      return res;
  }
};


/*
 * Complete the function below.
 */
vector <int> implement_LRU_cache(int capacity, vector <int> query_type, vector <int> key, vector <int> value) {
    
    nlru * niklru = new nlru(capacity);
    vi res;
    
    for(int i=0; i < query_type.size(); ++i ){
        int temp_res =-1;
        switch(query_type[i]){
            case 0: temp_res= niklru->get(key[i]);
                    res.pb(temp_res);
                    break;
            case 1:
                    niklru->set(key[i], value[i]);
                    break;
        }
        
    }
    
    return res;

}

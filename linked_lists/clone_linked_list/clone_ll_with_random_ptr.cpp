/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <unordered_map>
typedef unordered_map<RandomListNode *, RandomListNode*> myMap;
typedef pair<RandomListNode *, RandomListNode*> myMap_pair;

class Solution {
public:
    RandomListNode * getclonedlist(RandomListNode * node_ptr,myMap & m1 ){
        
        if(node_ptr == NULL)
            return NULL;
        
        auto res = m1.find(node_ptr);
        if ( res == m1.end()){
            RandomListNode * n = new RandomListNode(node_ptr->label);
            m1.insert(myMap_pair(node_ptr, n));
            return n;
        } else {
            return res->second;
        }
        
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        myMap m1;
        
        RandomListNode * temp = head;
        RandomListNode * nptr = NULL;
       
        while(temp != NULL){
            RandomListNode * c_ptr = getclonedlist(temp, m1);
            
            if( temp->next != NULL){
                c_ptr->next =  getclonedlist(temp->next, m1);
            } 
            
            if(temp->random != NULL){
                c_ptr->random = getclonedlist(temp->random, m1);
            }
            
            temp = temp->next;
        }
    
        return getclonedlist(head, m1);
    }
};

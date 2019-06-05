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
    
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        myMap m1;
        
        RandomListNode * new_head = NULL;
        RandomListNode * new_temp = NULL;
        RandomListNode * curr =head;
        RandomListNode* prev_curr = NULL;
        RandomListNode * prev_new = NULL;
        while(curr != NULL){
            auto res = m1.find(curr);
            if(res == m1.end()){
                RandomListNode *n = new RandomListNode(curr->label);
                // add to map
                m1.insert(myMap_pair(curr, n));
                       
                // make the right link
                if(prev_curr == NULL){
                    new_head = n;
                    new_temp =n;
                    
                }else {
                    prev_new->next = n;
                }
                
               // random pointer association
                if(curr->random != NULL){
                    RandomListNode *orig_random = curr->random;
                    auto rand_res = m1.find(orig_random);
                    if(rand_res == m1.end()){
                        RandomListNode * rand_node = new RandomListNode(orig_random->label);
                        // add to map
                        m1.insert(myMap_pair(orig_random, rand_node));
                        n->random = rand_node;
                    } else {
                        n->random = rand_res->second;
                    }
                }
                
                prev_new = n;
                
            }else {
                // seems like a no-op 
                prev_new->next = res->second;
                // random pointer association
                if(prev_curr->random != NULL){
                    RandomListNode *orig_random = prev_curr->random;
                    auto rand_res = m1.find(orig_random);
                    if(rand_res == m1.end()){
                        RandomListNode * rand_node = new RandomListNode(orig_random->label);
                        // add to map
                        m1.insert(myMap_pair(orig_random, rand_node));
                        prev_new->random = rand_node;
                    } else {
                        (res->second)->random = rand_res->second;
                    }
                }
                
                prev_new = res->second;
                
            }
            prev_curr = curr;
            curr = curr->next;

        }
        
        
        return new_head;
    }
};

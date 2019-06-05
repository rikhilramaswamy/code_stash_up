/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
/*
no need for DFS_main() because head node has connections to all other nodes in the graph 
*/


class Solution {
public:
   void cloneGraph_helper(UndirectedGraphNode *orig_node, unordered_set<int> & s1, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m1 ) {
        typedef pair<UndirectedGraphNode *, UndirectedGraphNode* > myMap_pair;
        s1.insert(orig_node->label);
        
        // create a node in the cloned graph if mapping is absent
        auto it = m1.find(orig_node);
         UndirectedGraphNode *orig_equi = NULL;
        if(it == m1.end()){
            orig_equi = new UndirectedGraphNode(orig_node->label);
            m1.insert(myMap_pair(orig_node, orig_equi));
        } else {
            orig_equi = it->second;
        }
        
        for(auto elem : orig_node->neighbors){
            int val = elem->label;
            auto itr = s1.find(val);
            if(itr == s1.end()){
                cloneGraph_helper(elem, s1, m1);
            }
            
            // make edge between orig and elem
            auto nitr = m1.find(elem);
            assert(nitr != m1.end());
            UndirectedGraphNode * nelem = nitr->second;
            orig_equi->neighbors.push_back(nelem);
        }
        
        
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode * ptr = NULL;
        if(node == NULL){
            return NULL;
        }
        
        typedef unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
        typedef pair<UndirectedGraphNode *, UndirectedGraphNode* > myMap_pair;
        typedef unordered_set<int> mySet;
        myMap m1;
        mySet s1;
        
        
        cloneGraph_helper(node, s1, m1);
        
        auto itr = m1.find(node);
        assert(itr != m1.end());
        
       
        return itr->second;
        
    }
};

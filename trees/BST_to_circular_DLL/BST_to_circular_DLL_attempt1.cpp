/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *treeToDoublyList_helper(Node *t, Node **beg){
        
        // base cases:
	// TODO: do we need this?
        if(t == NULL)
            return NULL;
        
        // if leaf return t
        if(t->left == NULL && t->right == NULL){
            if(*beg == NULL){
                (*beg) = t;
            }
            return t;
        }
        
        // transitions
        Node * n = NULL;
        n = treeToDoublyList_helper(t->left, beg);
        if(t->left != NULL){
            t->left = n;
            n->right = t;
        }
        
        Node *m = NULL;
        m = treeToDoublyList_helper(t->right, beg);
        if(t->right != NULL){
            t->right = m;
            m->left = t;
        }
        
        if(m != NULL) 
            return m;
        else 
            return t;
    }
    
    Node* treeToDoublyList(Node* root) {
        // store the beginnning node 
        Node * temp = NULL;
        if(root == NULL)
            return NULL;
        treeToDoublyList_helper(root, &temp );
 
	// make the DLL into a circular DLL by connecting beg and end node       
        assert( temp != NULL);
        Node * beg = temp;
        while (beg->right != NULL){
            beg = beg->right;
        }
        
        beg->right = temp;
        temp->left = beg;
        
        return temp;
        
    }
};

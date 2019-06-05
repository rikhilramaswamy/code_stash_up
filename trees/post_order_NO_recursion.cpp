#include <stack>
typedef pair<Node *, int> mypair;
typedef stack<mypair> sp;

/*
 * Complete the function below.
 */
void postorderTraversal(Node* root) {

    sp sp1;
    if(root == nullptr)
        return;
    
    sp1.push(mypair(root, 1));
    
    while(!sp1.empty()){
        mypair temp_pair = sp1.top();
        Node *curr = temp_pair.first;
        
        sp1.pop();
        // it is a node 
        if(temp_pair.second){
            sp1.push(mypair(curr, 0));
            
            
            if(curr->right != nullptr){

                sp1.push(mypair(curr->right,1));
            }
            
            if(curr->left != nullptr){
                sp1.push(mypair(curr->left,1));
            }
            
        } else {
            // it is just a value; we are done including children on stack
             cout<<curr->val<<" ";
        }
        
        
    }
    

}



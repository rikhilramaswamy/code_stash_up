/*
 * Complete the function below.
 */


/* find_lca using return values 
Node* findLCA(Node* root, int n1, int n2) {
    
    if(root == NULL)
        return NULL;
    
    if( root->val ==n1 || root->val == n2)
            return root;
    
    Node *left_lca = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
    
    if(left_lca && right_lca)
        return root;
    
    if(left_lca)
        return left_lca;
    
    return right_lca;   
}*/


void findLCA_helper(Node *root, int n1, int n2, Node **lca ) {
    if(root == NULL) {
        (*lca) = NULL;
        return;
    }
    if(root->val == n1 || root->val == n2){
        (*lca) = root;
        return;
        
    }
    
    
    Node *left_lca;
    findLCA_helper(root->left, n1, n2, &left_lca);
    
    Node *right_lca;
    findLCA_helper(root->right, n1, n2, &right_lca);
    
    if(left_lca && right_lca) {
        (*lca) = root;
        return;
    }
    
    if(left_lca){
        (*lca) = left_lca;
        return;
    }
    
    if(right_lca) {
        
        (*lca) = right_lca;
        return;
    }
    
    
    (*lca) = NULL;
    
}

Node* findLCA(Node* root, int n1, int n2) {
    Node *lca= NULL;
    findLCA_helper(root, n1, n2, &lca);
    
    return lca;
}


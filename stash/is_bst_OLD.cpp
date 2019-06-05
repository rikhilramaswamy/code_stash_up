#define INVALID -1774

/*
 * Complete the function below.
 */
bool isBST_Helper(Node *curr, int less_than, int greater_than){
    if(curr == NULL)
        return true;
    
    if(less_than != INVALID){
        if(curr->val >= less_than )
            return false;
    }
    
    if(greater_than != INVALID){
        if(curr->val <= greater_than)
            return false;
        
    }
    
    
    return (isBST_Helper(curr->left, curr->val,greater_than) && isBST_Helper(curr->right,less_than,curr->val ));
    
    
}


/*bool is_bst_inorder_prev(Node *t, Node** prev) {
    if( t == nullptr)
        return true;
    
    if(!is_bst_inorder_prev(t->left, prev)) return false;
    
    if((*prev) != nullptr && (*prev)->val >= t->val) return false;
    
    (*prev) = t;
    
    return is_bst_inorder_prev(t->right, prev);
}


bool isBST(Node *root) {

    Node *prev = nullptr;
    return is_bst_inorder_prev(root, &prev);

}*/



bool is_bst_inorder_prev(Node *t, int * prev) {
    if( t == nullptr)
        return true;
    
    if(!is_bst_inorder_prev(t->left, prev)) return false;
    
    if((prev) != nullptr && (*prev) >= t->val) return false;
    
    /*
    if(prev == nullptr) {
        prev = new int(t->val);
    } else 
        (*prev) = t->val;
    */
    return is_bst_inorder_prev(t->right, prev);
}


bool isBST(Node *root) {

    int *prev = nullptr;
    return is_bst_inorder_prev(root, prev);

}


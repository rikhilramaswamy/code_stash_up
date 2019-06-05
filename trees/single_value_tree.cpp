/*
 * Complete the function below.
 */
/*int findSingleValueTrees(Node* node) {
    
    if(node == nullptr)
        return 0;
    
    if(node->left == nullptr && node->right == nullptr)
        return 1;
    
    int left =0;
    int right=0; 
    
    if(node->left != nullptr)
        left = findSingleValueTrees(node->left);
    
    if(node->right != nullptr)
        right = findSingleValueTrees(node->right);
    
    if(node->left != nullptr && node->left->val == node->val && node->right !=nullptr  && node->right->val == node->val  )
        return 1 + left + right;
    if(node->left == nullptr && node->right !=nullptr && node->right->val == node->val )
        return 1 + left + right;
    
    if(node->right == nullptr && node->left != nullptr &&node->left->val == node->val )
            return 1 + left + right; 
    
        
    return left + right;

}*/

bool solve(Node * node, int * unival_cnt) {
    if(node == NULL) {
        (*unival_cnt) =0;
        return true;
    }
    int left_cnt =0;
    int right_cnt= 0;
    bool left_unival = solve(node->left, &left_cnt);
    bool right_unival = solve(node->right, &right_cnt);
    Node* left_node = node->left;
    Node * right_node = node->right;
    
    if(left_unival && right_unival) {
        if( left_node== NULL && right_node == NULL) {    
            ++(*unival_cnt);
            return true;
        } else if(left_node == NULL && right_node != NULL  && node->val == right_node->val) {
            (*unival_cnt) = right_cnt +1;
            return true;
        } else if (right_node == NULL && left_node != NULL && node->val == left_node->val) {
            (*unival_cnt) = left_cnt +1;
            return true;
        } else if (right_node != NULL && left_node != NULL && left_node->val == node->val && right_node->val == node->val ){
            (*unival_cnt)  = left_cnt + right_cnt +1;
            return true;
        }
        
    }
    (*unival_cnt) = left_cnt + right_cnt;
    return false;
    
    
    
    
}


int findSingleValueTrees(Node* node) {
    int unival_cnt =0;
    solve(node, &unival_cnt);
    
    return unival_cnt;
    
    
}



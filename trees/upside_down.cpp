/*
 * Complete the function below.
 */

void make_prev_pointers(Node *t, Node **prev) {
    if(t == NULL)
        return;
    
    Node * temp = t->left;
    t->left = (*prev);
    (*prev) = t;
    
    make_prev_pointers(temp, prev);
}


void handle_right_pointers(Node * t, Node **nr, Node **nhead){
    if(t == NULL)
        return;
    
    if(t->left == NULL) {
        (*nhead)= t;
        return;
    }
    
    Node *cr = (*nr);
    (*nr) = (t->left)->right;
    (t->left)->right = cr;
    t->right = NULL;
    
    handle_right_pointers(t->left, nr, nhead);
}

void swap_left_right_nodes(Node * t) {
    if(t == NULL)
        return;
    
    Node * temp = t->left;
    t->left = t->right;
    t->right = temp;
    
    swap_left_right_nodes(t->left);
    swap_left_right_nodes(t->right);
}


/* Node* upside_down(Node* node) {
    Node* nh = NULL;
    if(node == NULL)
        return NULL;
    
    Node *nr=node->right;
    handle_right_pointers(node, &nr,&nh );
    
    Node * prev = NULL;
    make_prev_pointers(node, &prev);
    
    swap_left_right_nodes(nh);
    
    return nh;
}*/


/*Node* upside_down(Node* node) {
    Node* nh = NULL;
    if(node == NULL)
        return NULL;
    
    if(node->left == NULL)
        return node;
    
    Node *temp = upside_down(node->left);
    
    node->left->left = node->right;
    node->left->right  = node;
    node->right = NULL;
    node->left = NULL;
    
    return temp;
}*/



void upside_down_helper(Node* node, Node ** nh) {
    if(node == NULL)
        return ;
    
    if(node->left == NULL) {
        (*nh) = node;
        return ;
    }
    
     upside_down_helper(node->left, nh);
    
    node->left->left = node->right;
    node->left->right  = node;
    node->right = NULL;
    node->left = NULL;
    
    return;
}

Node* upside_down(Node* node) { 
    Node *nh = NULL;
    
    upside_down_helper(node, &nh);
    
    return nh;
    
    
}


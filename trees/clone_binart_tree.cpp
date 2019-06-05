/*
 * Complete the function below.
 */
Node* cloneTree(Node* node) {
    if (node == nullptr)
        return  nullptr;
    Node *new_ptr = new Node(node->val);
    
    new_ptr->left = cloneTree(node->left);
    new_ptr->right = cloneTree(node->right);
    
    return new_ptr;

}



/*
 * Complete the function below.
 */
Node* flipTree(Node* node) {

    if( node == nullptr)
        return nullptr;
    
    Node * temp = node->left;
    node->left = node->right;
    node->right = temp;
    flipTree(node->left);
    flipTree(node->right);
    return node;

}

typedef vector<int> vi;
#define pb push_back
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)

void io_dll(Node *root, Node** base, Node** back) {
                if(root == NULL)
                        return;

                //cout<<"\nio_dll NTRIG:: "<<root->val;
                io_dll(root->left, base, back);

                Node * cr = NULL;
                        cr = root->right;
                if(*base == NULL) {
                        //cout<<"\n base NULL block: \tval:"<<root->val;
                        *base = root;
                        *back = *base;
                        (*back)->right = NULL;
                } else {
                        if((*back) != NULL) {
                                //cout<<"\n back : "<<(*back)->val;
                                (*back)->right = root;
                                (*back) = root;
                                (*back)->right = NULL;
                        }

                }

                io_dll(cr, base, back);

        }



 Node*  create_back_pointers(Node *temp) {
                //cout<<"\n printing the SLL contents...";
                Node *prev = NULL;
                while(temp != NULL) {
                        //cout<<"\t"<<temp->val;
                        temp->left = prev;
                        prev = temp;
                        temp= temp->right;


                }
                return prev;

}


void BSTtoLL_helper(Node *root, vi & res){
    if(root == NULL)
        return;
    BSTtoLL_helper(root->left, res);
    res.pb(root->val);
    BSTtoLL_helper(root->right, res);
}


void print_DLL(Node *temp){
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp= temp->right;
        
    }
    
}


/*
 * Complete the function below.
 */
void BSTtoLL(Node* root) {
     vi res;
      Node *base = NULL;
      Node *back = NULL;
    // this method will create a SLL with forward pointers  
    io_dll(root, &base, &back );
    
    // this will create the backword pointers completing the DLL
    create_back_pointers(base);
    
    print_DLL(base);
    
    
    
     
}



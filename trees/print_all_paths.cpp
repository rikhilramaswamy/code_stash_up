typedef vector<int> vi;
#define pb push_back
#define cont_tr(container, it) \
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)
/*
 * Complete the function below.
 */
void printAllPaths_helper(Node *root, vi &  res){
    if(root == NULL){
        return;
    }
   // cout<<"\n printAllPaths_helper with val:"<<root->val;
    res.pb(root->val);
    
    if(root->left == NULL && root->right == NULL ){
        //cout<<"\n printAllPaths_helper both NULL";
        if(!res.empty()){
            cont_tr(res, it){
                cout<<(*it)<<" ";
            }
            res.pop_back();
        }
        cout<<"\n";     
        return;
    }
    
    if(root->left != NULL)
        printAllPaths_helper(root->left, res);
    
    if(root->right != NULL)
        printAllPaths_helper(root->right, res);
   
    if(!res.empty())
        res.pop_back();
     
}



void printAllPaths(Node* root) {

    vi res;
    printAllPaths_helper(root, res);

}



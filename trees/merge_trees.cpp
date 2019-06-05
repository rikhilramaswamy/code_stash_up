typedef vector<int> vi;
#define pb push_back
#define cont_tr(container, it)\
    for(decltype(container.begin()) it = container.begin(); it != container.end(); ++it)

#include <stack>
typedef pair<Node *, int> mypair;
typedef stack<mypair> sp;


void inorderTraversal(Node *root, vi& res){
    if(root == NULL)
        return;
    
    if(root->left != NULL)
    inorderTraversal(root->left, res);
        //res.pb(root->val);
    cout<<" "<<root->val;
    if(root->right != NULL)
    inorderTraversal(root->right, res);
      
}

vi merge_sorted_vi(vi &v1, vi &v2){

    
    int v1_size = v1.size();
    int v2_size = v2.size();
    
    vi res;
    
    int i1 = 0;
    int i2=0;
    while( i1 <v1_size && i2 < v2_size  ){
        if(v1[i1] <= v2[i2]){
            res.pb(v1[i1]);
            i1++;
        } else {
             res.pb(v2[i2]);
            i2++;
            
        }
        
        
    }
    
    if(i1 <v1_size){
         res.pb(v1[i1]);
            i1++;
        
    }
    
    if(i2 < v2_size) {
        res.pb(v2[i2]);
            i2++;
    }
    
    return res;
}

Node * bottom_up_bst(vi &res,int  low,int  high){
    if(low > high)
        return NULL;
    
    int mid = (low +high)/2;
    Node * n = new Node(res[mid]);
    
    if(low == high)
        return n;
    
    n->left = bottom_up_bst(res, low, mid-1);
    n->right = bottom_up_bst(res, mid+1, high);
    
    return n;
     
}



/*
 * Complete the function below.
 */
Node* mergeTrees(Node* n1, Node* n2) {
    vi v1;
    inorderTraversal(n1, v1);
    vi v2;
    inorderTraversal(n2, v2);
    
    /*
    cout<<"\n vec1 v1...";
    cont_tr(v1, it){
        cout<<"\t "<<(*it);
        
    }*/
    
    //cout<<"\n\n";
    //cout<<"\n vec2 v2...";
   /* cont_tr(v2, it2){
        cout<<"\t "<<(*it2);
        
    }*/
    
    vi res = merge_sorted_vi(v1, v2);
    int res_sz = res.size()-1;
    
     /*cout<<"\n vec1 v1...";
    cont_tr(res, it){
        cout<<"\t "<<(*it);
        
    }*/
    
    return bottom_up_bst(res, 0, res_sz );
    //return NULL;
    

}



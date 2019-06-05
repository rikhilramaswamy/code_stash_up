/*
bool is_bst_inorder_prev(Node *t, Node** prev, int *count) {
    if( t == nullptr)
        return true;
    
    if(!is_bst_inorder_prev(t->left, prev, count)) return false;
    
    if((*prev) != nullptr && (*prev)->val >= t->val) return false;
    
    (*prev) = t;
    (*count)++;
    
    return is_bst_inorder_prev(t->right, prev, count);
}


bool isBST(Node *root, int *count) {

    Node *prev = nullptr;
    return is_bst_inorder_prev(root, &prev, count);

}


void findLargestBST_helper(Node *t, int *num_nodes) {
    if(t == NULL) {
        (*num_nodes) = 0;
        return ;
    }
    
    // check if sub-tree rooted at current node is BST 
    int cnt =0;
    if(isBST(t,&cnt)) {
        
        (*num_nodes) = cnt;
        return;
    }
    
    int lc=0, rc =0;
    findLargestBST_helper(t->left, &lc);
    findLargestBST_helper(t->right, &rc);
    
    (*num_nodes)  = max(lc,rc);
    return;
}



int  findLargestBST_helper2(Node *t) {
    if(t == NULL) {
       
        return 0 ;
    }
    
    // check if sub-tree rooted at current node is BST 
    int cnt =0;
    if(isBST(t,&cnt)) {
        return cnt;
    }
    
    return max(findLargestBST_helper2(t->left), findLargestBST_helper2(t->right));
}

int findLargestBST(Node* node) {
     int num_nodes =0;   
   // findLargestBST_helper(node, &num_nodes);
    //return num_nodes;
    return findLargestBST_helper2(node);
    

}

*/





#include<algorithm>
#include<climits>

/***
** Global pointer is literally just one copy for saving the result state ; ex: num_nodes
** Intermediate pointer:  is used for percolating the results up the tree; ex: left_bst, left_min and left_max
********* NOTE: return values can also help you percolate the result; When you need more than one value to be percolated up you need these intermediate pointers

*/


int solve (Node *t, int *minn, int *maxx, bool *bst, int * num_nodes){
    if( t == NULL) {
        (*bst) = true;
        return 0;
        
    }
    
    bool left_valid; bool left_bst = false; 
    int left_min = INT_MAX;
    int left_max = INT_MIN;
    //int left_size = solve(t->left, &left_min,&left_max, bst, num_nodes );
        int left_size = solve(t->left, &left_min,&left_max, &left_bst, num_nodes );


    
    //left_valid = *bst && t->val > (left_max);
        left_valid =  left_bst && t->val > (left_max);


    
    
    int temp_min = min(t->val, left_min);
    int temp_max = max(t->val, left_max);
    
   
    
    
bool right_valid; bool right_bst = false;
    int right_min = INT_MAX;
    int right_max = INT_MIN;
    //int right_size= solve(t->right, &right_min, &right_max, bst, num_nodes);
        int right_size= solve(t->right, &right_min, &right_max, &right_bst, num_nodes);


    
    
    temp_min = min(temp_min,right_min );
    temp_max = max(temp_max, right_max);

    //right_valid = *bst && t->val < right_min;
    right_valid = right_bst && t->val < right_min;

    
    (*minn) = temp_min;
    (*maxx) = temp_max;
    
    if(left_valid && right_valid){
        int temp = left_size + right_size +1;
        if(temp > (*num_nodes)) 
            (*num_nodes) =temp;
        
        (*bst) = true;
        return temp;
        
    }
    
    (*bst) = false;
    return 0; 
    
}



int findLargestBST(Node* node) {
     int num_nodes =0;   
    int minn = INT_MAX;
    int maxx = INT_MIN;
    bool bst = false;
    solve(node,&minn, &maxx, &bst,&num_nodes);
    return num_nodes;

}
